// ShellSort.cpp
#include "shellSort.hpp"

ShellSort::ShellSort(int* dados, int n) : Sort(dados, n) {}

void ShellSort::ordenar() {
    int gaps[20];
    int ultimo = 0;

    for (int g = 1; g < n; g = g * 3 + 1)
        gaps[ultimo++] = g;

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
