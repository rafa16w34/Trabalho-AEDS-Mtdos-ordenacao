#include <iostream>
#include "shellSort.hpp"
#include "arquivo.hpp"
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    int *dados = new int[1000000]; 

    auto inicio = high_resolution_clock::now();

    int n = lerArquivo(dados);     

    shellSort(dados, n);

    escreverResultado(dados);

    auto fim = high_resolution_clock::now();

    auto duracao = duration_cast<milliseconds>(fim - inicio);

    cout << "Tempo: " << duracao.count() << " ms\n";

    delete[] dados; 

    return 0;
}

    
