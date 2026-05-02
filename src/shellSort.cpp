#include <iostream>

void shellSort(int shellDados[], int n) {

    int gap = 1;

    // gera maior gap válido
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }

    // percorre a sequência de trás pra frente
    while (gap > 0) {

        for (int i = gap; i < n; i++) {

            int temp = shellDados[i];
            int j = i;

            while (j >= gap && shellDados[j - gap] > temp) {
                shellDados[j] = shellDados[j - gap];
                j -= gap;
            }

            shellDados[j] = temp;
        }

        gap = (gap - 1) / 3;
    }
}

void combSort(int dados[], int k) {

    double shrink = 1.3;
    int gap = k;
    bool sorted = false;

    while (!sorted) {
        gap = (int)(gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = true;  // assume ordenado; troca desfaz isso
        }

        for (int i = 0; i + gap < k; i++) {
            if (dados[i] > dados[i + gap]) {
                std::swap(dados[i], dados[i + gap]);
                sorted = false;  // houve troca, precisa de mais uma passada
            }
        }
    }
}