#include <iostream>
#include <chrono>
#include <cstring>
#include "sort.hpp"
#include "arquivo.hpp"

using namespace std;
using namespace chrono;

int main() {

     int loop = 0;
     int* original = nullptr;
     int* shellDados = nullptr;
     int* combDados = nullptr;

     limpaOutput();

     while (loop != 15) {

          int n = contarElementos(loop);          // descobre o tamanho real

          //--------------------------------------------------------------------------------------------

          original   = new int[n];               // aloca exato
          shellDados = new int[n];
          combDados  = new int[n];

          //--------------------------------------------------------------------------------------------

          lerArquivo(original, loop);

          //--------------------------------------------------------------------------------------------

          memcpy(shellDados, original, n * sizeof(int));
          memcpy(combDados,  original, n * sizeof(int));

          //--------------------------------------------------------------------------------------------

          // Shell sort
          auto t0 = high_resolution_clock::now();
          shellSort(shellDados, n);
          auto t1 = high_resolution_clock::now();

          long long tempoShell = duration_cast<microseconds>(t1 - t0).count();
          
          // Comb Sort
          auto t2 = high_resolution_clock::now();
          combSort(combDados, n);
          auto t3 = high_resolution_clock::now();

          long long tempoComb = duration_cast<microseconds>(t3 - t2).count();

          //--------------------------------------------------------------------------------------------

          long long memoriaBytes = 3LL * n * sizeof(int);  // agora é o tamanho real

          escreverResultado(tempoShell, tempoComb, loop, memoriaBytes);

          delete[] original;
          delete[] shellDados;
          delete[] combDados;


          
          loop++;
     }

     return 0;
}
