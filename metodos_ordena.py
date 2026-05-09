import math
import time
import os
import tracemalloc
import sys

"""
--------------------------------------------------------- Shell Sort: ---------------------------------------------------------
"""
def shellSort(vetor):
    n = len(vetor)

    k = 1
    while (math.pow(3, k) - 1) // 2 < n:
        k += 1
    k -= 1

    while k > 0:
        garp = int((math.pow(3, k) - 1) // 2)

        i = garp
        while i < len(vetor):
            temp = vetor[i]
            j = i - garp
            while j >= 0 and vetor[j] > temp:
                vetor[j + garp] = vetor[j]
                j -= garp
            vetor[j + garp] = temp
            i += 1

        k -= 1

"""
--------------------------------------------------------- Comb Sort: ----------------------------------------------------------
"""
def combSort(vetor):
    garp = len(vetor)
    shrink = 1.3
    ordenado = False

    while not ordenado:
        garp = int(garp / shrink)
        if garp < 1:
            garp = 1
            ordenado = True

        i = 0
        while i + garp < len(vetor):
            if vetor[i] > vetor[i + garp]:
                vetor[i], vetor[i + garp] = vetor[i + garp], vetor[i]
                ordenado = False
            i += 1

"""
--------------------------------------------------------- Medir tempo e memoria: ----------------------------------------------
"""
def medir(func, vetor):
    v = vetor.copy()
    tracemalloc.start()
    inicio = time.perf_counter()
    func(v)
    tempo = time.perf_counter() - inicio
    _, pico = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    return tempo, pico  # tempo em segundos, pico em bytes

def formatar_tempo(segundos):
    us = segundos * 1_000_000
    if us < 1000:
        return f"{us:.0f} us"
    ms = segundos * 1_000
    if ms < 1000:
        return f"{ms:.0f} ms"
    return f"{segundos:.3f} s"

def formatar_mem(bytes_val):
    kb = bytes_val / 1024
    return f"{kb:.0f} KB"

"""
--------------------------------------------------------- Escrita de saida: ---------------------------------------------------
"""
def escrever_saida(caminho, algoritmo, vetor, tempo):
    with open(caminho, "w") as f:
        f.write(f"- Ordenacao {algoritmo}:\n")
        f.write(f"- Tempo: {tempo:.4f} segundos\n")
        f.write(f"- Total de elementos: {len(vetor)}\n\n")
        f.write("\n".join(map(str, vetor)) + "\n")

"""
--------------------------------------------------------- Main: ---------------------------------------------------------------
"""

mapa_pastas = {
    "crescente":   "Crescente",
    "decrescente": "Decrescente",
    "random":      "Desordenado-Ordenado"
}

mapa_exibicao = {
    "crescente":   "crescente",
    "decrescente": "decrescente",
    "random":      "random"
}

for pasta in mapa_pastas.values():
    os.makedirs(f"dados/Saida/{pasta}", exist_ok=True)

entrada_dir = "dados/Entrada"
arquivos = sorted(os.listdir(entrada_dir))

# Agrupa resultados por tamanho e tipo para o log de memória
resultados = {}

for nome_arquivo in arquivos:
    if not nome_arquivo.endswith(".dat"):
        continue

    caminho_entrada = os.path.join(entrada_dir, nome_arquivo)
    nome_base = nome_arquivo.replace("input_", "").replace(".dat", "")

    pasta_saida = "Desordenado-Ordenado"
    tipo_chave = "random"
    for chave, pasta in mapa_pastas.items():
        if nome_base.startswith(chave):
            pasta_saida = pasta
            tipo_chave = chave
            break

    # Extrai tamanho (ex: "10^6") do nome
    partes = nome_base.split("_")
    tamanho_str = partes[-1]  # ex: "10^6"

    with open(caminho_entrada, "r") as f:
        dados = [int(linha.strip()) for linha in f if linha.strip()]

    # Memória dos objetos (o vetor em si)
    mem_listetos = sys.getsizeof(dados) + sum(sys.getsizeof(x) for x in dados)

    # Mede Shell Sort
    t_shell, mem_shell = medir(shellSort, dados)
    print(f"Shell Sort [{nome_base}]: {formatar_tempo(t_shell)}")

    saida_shell = f"dados/Saida/{pasta_saida}/output_Shell_Sort_{nome_base}.dat"
    escrever_saida(saida_shell, "Shell Sort", sorted(dados), t_shell)

    # Mede Comb Sort
    t_comb, mem_comb = medir(combSort, dados)
    print(f"Comb Sort  [{nome_base}]: {formatar_tempo(t_comb)}")

    saida_comb = f"dados/Saida/{pasta_saida}/output_Comb_Sort_{nome_base}.dat"
    escrever_saida(saida_comb, "Comb Sort", sorted(dados), t_comb)

    # Guarda para o log
    chave_log = (tamanho_str, mapa_exibicao[tipo_chave])
    resultados[chave_log] = {
        "t_shell":    t_shell,
        "t_comb":     t_comb,
        "mem_shell":  mem_shell,
        "mem_comb":   mem_comb,
        "mem_list":    mem_listetos,
    }

# Escreve log de memória e tempo no formato solicitado
os.makedirs("dados/Saida", exist_ok=True)
with open("dados/Saida/log_memoria.dat", "w") as log:
    # Ordena por tamanho depois por tipo
    ordem_tipo = ["random", "crescente", "decrescente"]
    ordem_tam  = ["10^2", "10^3", "10^4", "10^5", "10^6"]

    for tam in ordem_tam:
        for tipo in ordem_tipo:
            chave = (tam, tipo)
            if chave not in resultados:
                continue
            r = resultados[chave]
            log.write(f"{tam} - {tipo}\n")
            log.write(f"Tempo Shell Sort:  {formatar_tempo(r['t_shell'])}\n")
            log.write(f"Tempo Comb Sort:   {formatar_tempo(r['t_comb'])}\n")
            log.write(f"Memoria Shell Sort: {formatar_mem(r['mem_shell'])}\n")
            log.write(f"Memoria Comb Sort:  {formatar_mem(r['mem_comb'])}\n")
            log.write(f"Memoria utilizada da lista de entrada: {formatar_mem(r['mem_list'])}\n")
            log.write("\n")

print("\nLog salvo em: dados/Saida/log_memoria.dat")