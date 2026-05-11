// CombSort.hpp
#pragma once
#include "sort.hpp"

class CombSort : public Sort {
public:
    CombSort(int* dados, int n);
    void ordenar() override;
};