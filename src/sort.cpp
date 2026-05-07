#include "sort.hpp"
#include <algorithm>
#include <cmath>

void shellSort(int dados[], int n) {

    // Pré-calcula toda a sequência de Knuth uma única vez
    // 1 * 3 + 1

    int k = (int)(log(2.0 * n + 1) / log(3.0));

    int gaps[k]; // (No caso do meu código uso k = 20 que já é o suficiente para 10⁶ elementos)

    int ultimo = 0;
    
    for (int g = 1; g < n; g = g * 3 + 1){

        gaps[ultimo++] = g;

    }

    // Percorre do maior gap para o menor
    for (int atual = ultimo - 1; atual >= 0; atual--) {

        int gap = gaps[atual];

        for (int i = gap; i < n; i++) {

            int temp = dados[i];
            int j = i;

            while (j >= gap && dados[j - gap] > temp) {
                dados[j] = dados[j - gap];
                j -= gap;
            }

            dados[j] = temp;
        }
    }
}

void combSort(int dados[], int n) {

    // gap * 10 / 13 equivale a gap / 1.3 sem usar float
    int gap = n;
    bool sorted = false;

    while (!sorted) {

        gap = gap * 10 / 13;
        if (gap < 1) gap = 1;
        sorted = (gap == 1);

        for (int i = 0; i + gap < n; i++) {

            if (dados[i] > dados[i + gap]) {

                int t = dados[i];
                dados[i] = dados[i + gap];
                dados[i + gap] = t;
                sorted = false;
                
            }
        }
    }
}
