#include "arquivo.hpp"

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int lerArquivo(int dados[], int loop) {

    string nome;

    if      (loop == 0)  nome = "config/input_random_10^2.dat";
    else if (loop == 1)  nome = "config/input_crescente_10^2.dat";
    else if (loop == 2)  nome = "config/input_decrescente_10^2.dat";
    else if (loop == 3)  nome = "config/input_random_10^3.dat";
    else if (loop == 4)  nome = "config/input_crescente_10^3.dat";
    else if (loop == 5)  nome = "config/input_decrescente_10^3.dat";
    else if (loop == 6)  nome = "config/input_random_10^4.dat";
    else if (loop == 7)  nome = "config/input_crescente_10^4.dat";
    else if (loop == 8)  nome = "config/input_decrescente_10^4.dat";
    else if (loop == 9)  nome = "config/input_random_10^5.dat";
    else if (loop == 10) nome = "config/input_crescente_10^5.dat";
    else if (loop == 11) nome = "config/input_decrescente_10^5.dat";
    else if (loop == 12) nome = "config/input_random_10^6.dat";
    else if (loop == 13) nome = "config/input_crescente_10^6.dat";
    else if (loop == 14) nome = "config/input_decrescente_10^6.dat";
    else {
        cout << "Loop inválido: " << loop << "\n";
        return 0;
    }

    ifstream arquivo(nome);

    if (!arquivo) {
        cout << "Erro ao abrir " << nome << "\n";
        return 0;
    }

    int num, i = 0;

    while (arquivo >> num && i < 1000000) {
        dados[i++] = num;
    }

    arquivo.close();
    return i;
}

//------------------------------------------------------------------------------------

void limpaOutput(){

    ofstream arquivo("output.dat");

    if (!arquivo) {
        cout << "Erro ao abrir output.dat\n";
        exit;
    }

    arquivo.close();

}


//------------------------------------------------------------------------------------

int escreverResultado(long long tempoShell, long long tempoComb, int loop) {

    ofstream arquivo("output.dat", ios::app);

    if (!arquivo) {
        cout << "Erro ao abrir output.dat\n";
        return 1;
    }

    string titulo;

    if      (loop == 0)  titulo = "10^2 - random";
    else if (loop == 1)  titulo = "10^2 - crescente";
    else if (loop == 2)  titulo = "10^2 - decrescente";
    else if (loop == 3)  titulo = "10^3 - random";
    else if (loop == 4)  titulo = "10^3 - crescente";
    else if (loop == 5)  titulo = "10^3 - decrescente";
    else if (loop == 6)  titulo = "10^4 - random";
    else if (loop == 7)  titulo = "10^4 - crescente";
    else if (loop == 8)  titulo = "10^4 - decrescente";
    else if (loop == 9)  titulo = "10^5 - random";
    else if (loop == 10) titulo = "10^5 - crescente";
    else if (loop == 11) titulo = "10^5 - decrescente";
    else if (loop == 12) titulo = "10^6 - random";
    else if (loop == 13) titulo = "10^6 - crescente";
    else if (loop == 14) titulo = "10^6 - decrescente";
    else {
        cout << "Loop inválido: " << loop << "\n";
        return 0;
    }

    arquivo << "\n" << titulo << "\n";
    arquivo << "Tempo Shell Sort: " << tempoShell << " ms\n";
    arquivo << "Tempo Comb Sort:  " << tempoComb  << " ms\n";

    arquivo.close();
    return 0;
}