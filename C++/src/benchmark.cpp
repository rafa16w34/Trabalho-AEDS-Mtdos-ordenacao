#include "benchmark.hpp"
#include "arquivo.hpp"
#include "shellSort.hpp"
#include "combSort.hpp"

#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>

using namespace std;
using namespace chrono;

string Benchmark::getNome() {
    if      (loop == 0)  return "config/input_random_10^2.dat";
    else if (loop == 1)  return "config/input_crescente_10^2.dat";
    else if (loop == 2)  return "config/input_decrescente_10^2.dat";
    else if (loop == 3)  return "config/input_random_10^3.dat";
    else if (loop == 4)  return "config/input_crescente_10^3.dat";
    else if (loop == 5)  return "config/input_decrescente_10^3.dat";
    else if (loop == 6)  return "config/input_random_10^4.dat";
    else if (loop == 7)  return "config/input_crescente_10^4.dat";
    else if (loop == 8)  return "config/input_decrescente_10^4.dat";
    else if (loop == 9)  return "config/input_random_10^5.dat";
    else if (loop == 10) return "config/input_crescente_10^5.dat";
    else if (loop == 11) return "config/input_decrescente_10^5.dat";
    else if (loop == 12) return "config/input_random_10^6.dat";
    else if (loop == 13) return "config/input_crescente_10^6.dat";
    else if (loop == 14) return "config/input_decrescente_10^6.dat";
    return "";
}

string Benchmark::getTitulo() {
    if      (loop == 0)  return "10^2 - random";
    else if (loop == 1)  return "10^2 - crescente";
    else if (loop == 2)  return "10^2 - decrescente";
    else if (loop == 3)  return "10^3 - random";
    else if (loop == 4)  return "10^3 - crescente";
    else if (loop == 5)  return "10^3 - decrescente";
    else if (loop == 6)  return "10^4 - random";
    else if (loop == 7)  return "10^4 - crescente";
    else if (loop == 8)  return "10^4 - decrescente";
    else if (loop == 9)  return "10^5 - random";
    else if (loop == 10) return "10^5 - crescente";
    else if (loop == 11) return "10^5 - decrescente";
    else if (loop == 12) return "10^6 - random";
    else if (loop == 13) return "10^6 - crescente";
    else if (loop == 14) return "10^6 - decrescente";
    return "desconhecido";
}

void Benchmark::alocar() {
    original   = new int[n];
    shellDados = new int[n];
    combDados  = new int[n];
}

void Benchmark::liberar() {
    delete[] original;
    delete[] shellDados;
    delete[] combDados;
    original = shellDados = combDados = nullptr;
}

long long Benchmark::getMemoriaKB() {
    ifstream status("/proc/self/status");
    string linha;
    while (getline(status, linha)) {
        if (linha.rfind("VmRSS:", 0) == 0) {
            long long kb;
            sscanf(linha.c_str(), "VmRSS: %lld", &kb);
            return kb;
        }
    }
    return 0;
}

Benchmark::Benchmark(int loop)
    : original(nullptr), shellDados(nullptr), combDados(nullptr),
      n(0), loop(loop), tempoShell(0), tempoComb(0), memoriaBytes(0) {}

Benchmark::~Benchmark() {
    liberar();
}

void Benchmark::carregar() {
    // conta e aloca
    ifstream arq(getNome());
    int count = 0, num;
    while (arq >> num) count++;
    n = count;

    alocar();

    // lê de novo para preencher
    ifstream arq2(getNome());
    int i = 0;
    while (arq2 >> num) original[i++] = num;

    memcpy(shellDados, original, n * sizeof(int));
    memcpy(combDados,  original, n * sizeof(int));

    memoriaBytes = 3LL * n * sizeof(int);
}

void Benchmark::executar() {
    ShellSort shell(shellDados, n);
    CombSort  comb(combDados, n);

    // Shell Sort
    long long mem0 = getMemoriaKB();
    auto t0 = high_resolution_clock::now();
    shell.ordenar();
    auto t1 = high_resolution_clock::now();
    long long mem1 = getMemoriaKB();

    tempoShell   = duration_cast<microseconds>(t1 - t0).count();
    memoriaShell = mem1 - mem0;

    // Comb Sort
    long long mem2 = getMemoriaKB();
    auto t2 = high_resolution_clock::now();
    comb.ordenar();
    auto t3 = high_resolution_clock::now();
    long long mem3 = getMemoriaKB();

    tempoComb   = duration_cast<microseconds>(t3 - t2).count();
    memoriaComb = mem3 - mem2;
}



void Benchmark::salvar() {
    ofstream arq("output.dat", ios::app);
    arq << "\n" << getTitulo() << "\n";
    arq << "Tempo Shell Sort:  " << tempoShell  << " us\n";
    arq << "Tempo Comb Sort:   " << tempoComb   << " us\n";
    arq << "Memoria Shell Sort: " << memoriaShell << " KB\n";
    arq << "Memoria Comb Sort:  " << memoriaComb  << " KB\n";  
    arq << "Memoria utilizada pelos objetos: " << memoriaBytes / 1024 << " KB\n";
}