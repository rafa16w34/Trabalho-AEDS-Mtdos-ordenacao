#include "arquivo.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int lerArquivo(int dados[]) {
    ifstream arquivo("config/input.dat");
    if (!arquivo) {
        cout << "Erro ao abrir config/input.dat\n";
        return 0;
    }

    int num, i = 0;
    while (arquivo >> num && i < 1000000)
        dados[i++] = num;

    arquivo.close();
    return i;
}

int escreverResultado(int dados[]) {
    ofstream arquivo("output.dat");
    if (!arquivo) {
        cout << "Erro ao abrir output.dat\n";
        return 1;
    }

    for (int i = 0; i < 1000000; i++)
        arquivo << dados[i] << '\n';  // '\n' não faz flush, endl faz

    arquivo.close();
    return 0;
}
