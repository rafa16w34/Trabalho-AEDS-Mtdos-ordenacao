#include <iostream>
#include "shellSort.hpp"
#include "arquivo.hpp"
#include <chrono>

using namespace std;
using namespace chrono;

auto iniciarContador(){

    auto inicio = high_resolution_clock::now();

    return inicio;
    
}

auto pararContador(auto inicio){

    auto fim = high_resolution_clock::now();

    auto duracao = duration_cast<milliseconds>(fim - inicio);

    return duracao;

}

int main() {
    int *shellDados = new int[1000000]; 

    int *combDados = new int[1000000]; 

//--------------------------------------------------------------------------------------------------------------

    int n = lerArquivo(shellDados);  
    
    auto inicioShell = iniciarContador();

    shellSort(shellDados, n);

    auto duracaoShell = pararContador(inicioShell);

    delete[] shellDados; 

//-----------------------------------------------------------------------------------------------------------

    int k = lerArquivo(combDados);  

    auto inicioComb = iniciarContador();

    combSort(combDados, k);

    auto duracaoComb = pararContador(inicioComb);

    escreverResultado(combDados);

    cout << "Tempo (Shell Sort): " << duracaoShell.count() << " ms\n" << "Tempo (Comb Sort): " << duracaoComb.count() << "ms\n";

    delete[] combDados; 

    return 0;
}

    
