#include "shell.h"
#include "comb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Lê a memória residente atual (VmRSS) em kB via /proc/self/status.
   Funciona em Linux; em outros SOs retorna -1. */
static long get_mem_kb(void) {
    FILE *f = fopen("/proc/self/status", "r");
    if (!f) return -1L;
    char line[128];
    long kb = -1L;
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            sscanf(line + 6, "%ld", &kb);
            break;
        }
    }
    fclose(f);
    return kb;
}

/* Conta linhas não-vazias de um arquivo (= número de elementos). */
static int conta_linhas(FILE *arq) {
    int linhas = 0, c;
    while ((c = fgetc(arq)) != EOF)
        if (c == '\n') linhas++;
    rewind(arq);
    return linhas;
}

int main(void) {

    /* ---- lista de todos os inputs ---------------------------------- */
    const char *inputs[] = {
        "INPUT/input_crescente_10^2.dat",
        "INPUT/input_crescente_10^3.dat",
        "INPUT/input_crescente_10^4.dat",
        "INPUT/input_crescente_10^5.dat",
        "INPUT/input_crescente_10^6.dat",
        "INPUT/input_decrescente_10^2.dat",
        "INPUT/input_decrescente_10^3.dat",
        "INPUT/input_decrescente_10^4.dat",
        "INPUT/input_decrescente_10^5.dat",
        "INPUT/input_decrescente_10^6.dat",
        "INPUT/input_random_10^2.dat",
        "INPUT/input_random_10^3.dat",
        "INPUT/input_random_10^4.dat",
        "INPUT/input_random_10^5.dat",
        "INPUT/input_random_10^6.dat"
    };
    const int NUM_INPUTS = (int)(sizeof(inputs) / sizeof(inputs[0]));

    /* ---- arquivo de métricas consolidado --------------------------- */
    FILE *metricas = fopen("OUTPUT/metricas.dat", "w");
    if (!metricas) {
        fprintf(stderr, "Erro ao criar OUTPUT/metricas.dat\n");
        return 1;
    }

    fprintf(metricas,
        "%-40s | %12s | %14s | %14s | %14s\n",
        "Input", "N", "Shell (s)", "Comb (s)", "Mem RSS (kB)");
    fprintf(metricas,
        "%-40s-+-%12s-+-%14s-+-%14s-+-%14s\n",
        "----------------------------------------",
        "------------", "--------------",
        "--------------", "--------------");

    /* ---- loop sobre cada input ------------------------------------- */
    for (int fi = 0; fi < NUM_INPUTS; fi++) {

        const char *caminho = inputs[fi];
        printf("Processando: %s\n", caminho);

        /* abre input */
        FILE *arq = fopen(caminho, "r");
        if (!arq) {
            fprintf(stderr, "  [ERRO] nao foi possivel abrir %s\n", caminho);
            fprintf(metricas, "%-40s | ERRO\n", caminho);
            continue;
        }

        int n = conta_linhas(arq);
        if (n <= 0) {
            fprintf(stderr, "  [AVISO] arquivo vazio: %s\n", caminho);
            fclose(arq);
            continue;
        }

        /* aloca vetores */
        int *vet      = malloc(n * sizeof(int));
        int *vetshell = malloc(n * sizeof(int));
        int *vetcomb  = malloc(n * sizeof(int));
        if (!vet || !vetshell || !vetcomb) {
            fprintf(stderr, "  [ERRO] malloc falhou para n=%d\n", n);
            free(vet); free(vetshell); free(vetcomb);
            fclose(arq);
            continue;
        }

        /* lê dados */
        for (int i = 0; i < n; i++)
            fscanf(arq, "%d", &vet[i]);
        fclose(arq);

        /* copia para os vetores de ordenação */
        memcpy(vetshell, vet, n * sizeof(int));
        memcpy(vetcomb,  vet, n * sizeof(int));

        /* ---- Shell Sort ---- */
        clock_t t0 = clock();
        shellsort(vetshell, n);
        clock_t t1 = clock();
        double tempo_shell = (double)(t1 - t0) / CLOCKS_PER_SEC;

        /* ---- Comb Sort ---- */
        memcpy(vetcomb, vet, n * sizeof(int));
        t0 = clock();
        combsort(vetcomb, n);
        t1 = clock();
        double tempo_comb = (double)(t1 - t0) / CLOCKS_PER_SEC;

        /* ---- memória após ordenações ---- */
        long mem_kb = get_mem_kb();

        /* ---- gera nome do arquivo de output ---- */
        const char *nome = strrchr(caminho, '/');
        nome = nome ? nome + 1 : caminho;

        char out_path[256];
        snprintf(out_path, sizeof(out_path), "OUTPUT/output_%s", nome);

        FILE *saida = fopen(out_path, "w");
        if (!saida) {
            fprintf(stderr, "  [ERRO] nao foi possivel criar %s\n", out_path);
        } else {
            fprintf(saida, "=== Input: %s  (N=%d) ===\n\n", caminho, n);

            fprintf(saida, "Vetor original:\n");
            for (int i = 0; i < n; i++)
                fprintf(saida, "%d\n", vet[i]);

            fprintf(saida, "\nVetor ordenado com Shell Sort:\n");
            for (int i = 0; i < n; i++)
                fprintf(saida, "%d\n", vetshell[i]);

            fprintf(saida, "\nVetor ordenado com Comb Sort:\n");
            for (int i = 0; i < n; i++)
                fprintf(saida, "%d\n", vetcomb[i]);

            fprintf(saida, "\n--- Metricas ---\n");
            fprintf(saida, "Tempo Shell Sort : %.6f s\n", tempo_shell);
            fprintf(saida, "Tempo Comb Sort  : %.6f s\n", tempo_comb);
            if (mem_kb >= 0)
                fprintf(saida, "Memoria RSS      : %ld kB\n", mem_kb);
            else
                fprintf(saida, "Memoria RSS      : N/A\n");

            fclose(saida);
            printf("  -> Saida: %s\n", out_path);
        }

        /* ---- linha na tabela de métricas ---- */
        if (mem_kb >= 0)
            fprintf(metricas, "%-40s | %12d | %14.6f | %14.6f | %14ld\n",
                    nome, n, tempo_shell, tempo_comb, mem_kb);
        else
            fprintf(metricas, "%-40s | %12d | %14.6f | %14.6f | %14s\n",
                    nome, n, tempo_shell, tempo_comb, "N/A");

        printf("  Shell: %.6f s  |  Comb: %.6f s  |  Mem: %ld kB\n",
               tempo_shell, tempo_comb, mem_kb);

        free(vet);
        free(vetshell);
        free(vetcomb);
    }

    fclose(metricas);
    printf("\nConcluido! Metricas em OUTPUT/metricas.dat\n");
    return 0;
}
