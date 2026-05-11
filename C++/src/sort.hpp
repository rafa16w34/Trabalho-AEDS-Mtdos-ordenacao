// Sort.hpp
#pragma once

class Sort {
protected:
    int* dados;
    int  n;

public:
    Sort(int* dados, int n);
    virtual ~Sort() = default;

    virtual void ordenar() = 0;  // método puramente virtual — cada filho implementa
};



