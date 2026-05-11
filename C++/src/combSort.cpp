
// CombSort.cpp
#include "combSort.hpp"
#include <algorithm>

CombSort::CombSort(int* dados, int n) : Sort(dados, n) {}

void CombSort::ordenar() {
    int gap = n;
    bool sorted = false;

    while (!sorted) {
        gap = gap * 10 / 13;
        if (gap < 1) gap = 1;
        sorted = (gap == 1);

        for (int i = 0; i + gap < n; i++) {
            if (dados[i] > dados[i + gap]) {
                std::swap(dados[i], dados[i + gap]);
                sorted = false;
            }
        }
    }
}