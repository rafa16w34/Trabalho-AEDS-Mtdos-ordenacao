#include <iostream>
#include <chrono>
#include <cstring>
#include "shellSort.hpp"
#include "arquivo.hpp"

using namespace std;
using namespace chrono;

int main() {
    // Lê o arquivo uma vez
    int* original = new int[1000000];
    int n = lerArquivo(original);

    // Copia para cada algoritmo (medir apenas a ordenação, não I/O)
    int* shellDados = new int[1000000];
    int* combDados  = new int[1000000];
    memcpy(shellDados, original, n * sizeof(int));
    memcpy(combDados,  original, n * sizeof(int));

    // Shell Sort
    auto t0 = high_resolution_clock::now();
    shellSort(shellDados, n);
    auto t1 = high_resolution_clock::now();

    // Comb Sort
    auto t2 = high_resolution_clock::now();
    combSort(combDados, n);
    auto t3 = high_resolution_clock::now();

    escreverResultado(combDados);

    cout << "Tempo Shell Sort: "
         << duration_cast<milliseconds>(t1 - t0).count() << " ms\n";
    cout << "Tempo Comb Sort:  "
         << duration_cast<milliseconds>(t3 - t2).count() << " ms\n";

    delete[] original;
    delete[] shellDados;
    delete[] combDados;
    return 0;
}
