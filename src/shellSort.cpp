#include <iostream>
#include <math.h>

void shellSort(int dados[], int n) {

    int gap = 1;

    // gera maior gap válido
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }

    // percorre a sequência de trás pra frente
    while (gap > 0) {

        for (int i = gap; i < n; i++) {

            int temp = dados[i];
            int j = i;

            while (j >= gap && dados[j - gap] > temp) {
                dados[j] = dados[j - gap];
                j -= gap;
            }

            dados[j] = temp;
        }

        gap = (gap - 1) / 3;
    }
}