#include "arquivo.hpp"

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int lerArquivo(int dados[]) {

    ifstream arquivo("config/input.dat");

    if (!arquivo) {
        cout << "Erro ao abrir config/input.dat\n";
        return 0;
    }

    int num, i = 0;

    while (arquivo >> num && i < 1000000){
        dados[i++] = num;
    }

    arquivo.close();
    return i;
}

int escreverResultado(int dados[],long long tempoShell, long long tempoComb) {

    ofstream arquivo("output.dat");

    if (!arquivo) {
        cout << "Erro ao abrir output.dat\n";
        return 1;
    }

    arquivo << "Tempo Shell Sort: " << tempoShell << " ms\n";
    arquivo << "Tempo Comb Sort:  " << tempoComb << " ms\n";

    arquivo.close();

    return 0;
}
