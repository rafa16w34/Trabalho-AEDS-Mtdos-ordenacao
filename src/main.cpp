#include "benchmark.hpp"
#include "arquivo.hpp"

int main() {
    limpaOutput();

    for (int loop = 0; loop < 15; loop++) {
        Benchmark b(loop);
        b.carregar();
        b.executar();
        b.salvar();
    }

    return 0;
}