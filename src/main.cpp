#include <iostream>
#include <chrono>
#include <cstring>
#include "sort.hpp"
#include "arquivo.hpp"

#define TAM 1000000

using namespace std;
using namespace chrono;

int main() {


     int* original = new int[TAM];
     int n = lerArquivo(original);

//--------------------------------------------------------------------------------------------

     int* shellDados = new int[TAM];
     int* combDados  = new int[TAM];

     memcpy(shellDados, original, n * sizeof(int));
     memcpy(combDados,  original, n * sizeof(int));

//--------------------------------------------------------------------------------------------

     // Shell sort
     auto t0 = high_resolution_clock::now();
     shellSort(shellDados, n);
     auto t1 = high_resolution_clock::now();

     long long tempoShell = duration_cast<milliseconds>(t1 - t0).count();
     
     // Comb Sort
     auto t2 = high_resolution_clock::now();
     combSort(combDados, n);
     auto t3 = high_resolution_clock::now();

     long long tempoComb = duration_cast<milliseconds>(t3 - t2).count();

//--------------------------------------------------------------------------------------------

     escreverResultado(combDados, tempoShell, tempoComb);

//--------------------------------------------------------------------------------------------


     delete[] original;
     delete[] shellDados;
     delete[] combDados;
     return 0;
}
