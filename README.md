# Trabalho de AEDS - Métodos de Ordenação

Este projeto implementa o algoritmo de ordenação **Shell Sort** em Java.
# Algoritmos de Ordenação — Shell Sort & Comb Sort

> Trabalho desenvolvido para a disciplina de **Algoritmos e Estruturas de Dados I (A.E.D.S.I)**  
> CEFET-MG, Campus V — Divinópolis, Brasil

Análise teórica e experimental dos algoritmos **Shell Sort** e **Comb Sort**, implementados em cinco linguagens de programação, avaliados sobre entradas de diferentes tamanhos e distribuições.

---

## Autores

| Nome | E-mail |
|---|---|
| Gabriel Alves Faria | gabrielalvesfaria@gmail.com |
| Rafael Alves Faria | rafael16alvesf@gmail.com |
| Anthony Gabriel Sotto Mayor Silva | anthonygabrielsotto29@gmail.com |
| Henrique Parreira Cavalcante de Souza | henriqueparreira2007@gmail.com |

---

## Sobre o Projeto

Os algoritmos Shell Sort e Comb Sort são refinamentos, respectivamente, do Insertion Sort e do Bubble Sort. Ambos utilizam a estratégia de comparações em intervalos maiores (gap variável) antes dos ajustes finais, tornando-os especialmente eficientes para grandes volumes de dados.

Este repositório contém as implementações em **C**, **C++**, **Java**, **Python** e **Go**, com experimentos conduzidos sobre permutações de inteiros no intervalo `[1, N]`, com tamanhos `N ∈ {10², 10³, 10⁴, 10⁵, 10⁶}` e três tipos de distribuição: **aleatória**, **crescente** e **decrescente**.

---

## Estrutura do Repositório

```
.
├── C/
│   ├── INPUT/                     # Arquivos de entrada dos testes
│   ├── OUTPUT/                    # Resultados gerados
│   ├── main.c                     # Programa principal
│   ├── shell.c                    # Implementação do Shell Sort
│   ├── comb.c                     # Implementação do Comb Sort
│   ├── shell.h                    # Definições do Shell Sort
│   ├── comb.h                     # Definições do Comb Sort
│   ├── Makefile                   # Automação da compilação
│   └── programa                   # Executável gerado
|
├── C++/
|   ├── config/                 # Arquivos de entrada dos testes
|   ├── src/
|   │   ├── main.cpp            # Programa principal
|   │   ├── benchmark.cpp       # Benchmark e coleta de métricas
|   │   ├── arquivo.cpp         # Manipulação de arquivos
|   │   ├── shellSort.cpp       # Implementação do Shell Sort
|   │   ├── combSort.cpp        # Implementação do Comb Sort
|   │   └── sort.cpp            # Funções auxiliares de ordenação
|   │
|   ├── Makefile                # Automação da compilação
|   ├── output.dat              # Resultados dos testes
|
├── Java/
│   ├── data/                      # Arquivos de entrada/saída
│   ├── src/                       # Código-fonte Java
│   ├── bin/                       # Arquivos compilados
│   └── out/                       # Saídas geradas pela IDE
|
├── Python/
|     ├── metodos_ordena.py          # Script principal
|     ├── Makefile                   # Automação de execução e limpeza
|     └── dados/
|          ├── Entrada/               # Arquivos de entrada (.dat)
|          └── Saida/                 # Arquivos de saida (.dat)
|
├── Go/
│   ├── INPUT/                     # Arquivos de entrada
│   ├── OUTPUT/                    # Resultados dos benchmarks
│   ├── sorts/                     # Implementações dos algoritmos
│   └── main.go                    # Programa principal
│
└── README.md
```

---

## Como Executar

### C++

Utiliza Makefile para compilação e execução:

```bash
make clean && make && make run
```

### Java

Compilar todos os arquivos `.java` do diretório:

```bash
javac src/*.java
java -cp src Main
```

### Python

Utiliza Makefile para execução:
Windows
```bash 
python metodos_ordena.py
```

Linux
```bash 
make clean && make && make run
```

### C

Utiliza Makefile para compilação e execução:

```bash
make clean && make && make run
```

### Go

```bash
go run
```


---

## Detalhes dos Algoritmos

### Shell Sort

- Refinamento do Insertion Sort proposto por Donald Shell em 1959
- Utiliza a **sequência de Knuth** (`h = h * 3 + 1`) para geração dos gaps
- Complexidades com sequência de Knuth:
  - Melhor caso: `O(n log n)`
  - Caso médio: `O(n^(3/2))` (estimativa empírica)
  - Pior caso: `O(n^(3/2))`
- In-place (`O(1)` de memória auxiliar), **não estável**, **adaptativo**

### Comb Sort

- Refinamento do Bubble Sort proposto por Dobosiewicz (1980) e popularizado por Lacey & Box (1991)
- Utiliza fator de encolhimento **1,3** (estabelecido após testes em mais de 200.000 listas)
- Complexidades:
  - Melhor caso: `O(n log n)`
  - Caso médio: próximo de `O(n log n)` (empírico)
  - Pior caso: `O(n²)`
- In-place (`O(1)` de memória auxiliar), **não estável**, **adaptativo**

---

## Resumo dos Resultados

Os experimentos foram conduzidos em uma máquina com processador **Intel U300 (1,20 GHz)** e **8 GB de RAM**, rodando **Ubuntu 24.04 LTS via WSL**.

Ferramentas utilizadas: GCC 13.3 (C e C++), OpenJDK 21 (Java), Python 3.12, Go 1.22.

### Desempenho para n = 10⁶ — Entrada Aleatória

| Linguagem | Shell Sort | Comb Sort |
|---|---|---|
| C | 0,1556 s | 0,1396 s |
| C++ | ~0,342 s | ~0,327 s |
| Java | ~0,172 s | ~0,115 s |
| Python | ~103 s | ~119 s |
| Go | ~0,183 s | ~0,179 s |

### Principais Conclusões

- **Shell Sort** é superior em entradas pré-ordenadas (crescente/decrescente) graças à sua adaptatividade
- **Comb Sort** supera o Shell Sort em entradas aleatórias de grande porte na maioria das linguagens (C, C++, Java, Go), pela eficiência na eliminação de *turtles*
- **C e C++** oferecem o melhor desempenho bruto; **Go** compete diretamente com consumo de memória controlado
- **Java** apresenta *warm-up* do JIT nas primeiras execuções, mas rivaliza com C++ em instâncias massivas
- **Python** registrou os maiores tempos devido ao overhead do interpretador CPython e à representação de inteiros como objetos no heap

---

## Referências

1. SHELL, D. L. *A High-Speed Sorting Procedure*. Communications of the ACM, v. 2, n. 7, p. 30–32, 1959.
2. LACEY, S.; BOX, R. *A Fast, Easy Sort*. Byte Magazine, v. 16, n. 4, p. 315–320, 1991.
3. KNUTH, D. E. *The Art of Computer Programming, Vol. 3: Sorting and Searching*. Addison-Wesley, 1973.
4. HIBBARD, T. N. *An Empirical Study of Minimal Storage Sorting*. Communications of the ACM, v. 6, n. 5, p. 206–213, 1963.
5. CIURA, M. *Best Increments for the Average Case of Shellsort*. ISFCT 2001, Springer, p. 106–117.
6. ZIVIANI, N. *Projeto de Algoritmos: com Implementações em Pascal e C*. 2. ed. Pioneira Thomson Learning, 2004.
