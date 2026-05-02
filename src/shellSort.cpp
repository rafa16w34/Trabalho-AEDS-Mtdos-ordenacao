#include "shellSort.hpp"
#include <algorithm>

void shellSort(int dados[], int n) {
    // Pré-calcula toda a sequência de Knuth uma única vez
    int gaps[20];
    int ng = 0;
    for (int g = 1; g < n; g = g * 3 + 1)
        gaps[ng++] = g;

    // Percorre do maior gap para o menor
    for (int gi = ng - 1; gi >= 0; gi--) {
        int gap = gaps[gi];
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
