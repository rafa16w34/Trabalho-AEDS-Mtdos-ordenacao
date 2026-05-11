// ShellSort.hpp
#pragma once
#include "sort.hpp"

class ShellSort : public Sort {
public:
    ShellSort(int* dados, int n);
    void ordenar() override;
};