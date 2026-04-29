#include <iostream>
#include <fstream>

using namespace std;

int lerArquivo(int dados[]) {

    ifstream arquivo("/home/rafa16w34/Documentos/GitHub/Trabalho-AEDS-Mtdos-ordenacao/config/input.dat");

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo\n";
        return 0;
    }

    int num, i = 0;

    while (arquivo >> num && i < 1000000) {
        dados[i++] = num;
    }

    arquivo.close();

    return i; 
}

int escreverResultado(int dados[]){

    ofstream arquivo("/home/rafa16w34/Documentos/GitHub/Trabalho-AEDS-Mtdos-ordenacao/output.dat");

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo\n";
        return 1;
    }

    for (int i = 0; i < 1000000; i++){
    
        arquivo << dados[i] << " ";
        arquivo << endl;

    }

    arquivo.close();

    return 0;

}