#pragma once
#include <string>

class Benchmark {
private:
    int*      original;
    int*      shellDados;
    int*      combDados;
    int       n;
    int       loop;
    long long tempoShell;
    long long tempoComb;
    long long memoriaBytes;
    long long memoriaShell;
    long long memoriaComb;

    std::string getNome();
    std::string getTitulo();
    void alocar();
    void liberar();

private:
    long long getMemoriaKB();

public:
    Benchmark(int loop);
    ~Benchmark();

    void carregar();
    void executar();
    void salvar();
};