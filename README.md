# Trabalho-AEDS-Mtdos-ordenacao-Shell Sort e Comb Sort em Python 
Trabalho em grupo sobre metodos de ordenação:

Implementação e análise experimental dos algoritmos **Shell Sort** e **Comb Sort** em Python, com medição de tempo de execução e consumo de memória para diferentes tamanhos e distribuições de entrada.

---

## Estrutura do Projeto

```
Trabalho2AEDSI_Python/
├── metodos_ordena.py          # Script principal
├── Makefile                   # Automação de execução e limpeza
└── dados/
    ├── Entrada/               # Arquivos de entrada (.dat)
    │   ├── input_crescente_10^2.dat
    │   ├── input_crescente_10^3.dat
    │   ├── input_crescente_10^4.dat
    │   ├── input_crescente_10^5.dat
    │   ├── input_crescente_10^6.dat
    │   ├── input_decrescente_10^2.dat  ... (10^6)
    │   └── input_random_10^2.dat       ... (10^6)
    └── Saida/
        ├── Crescente/         # Outputs das entradas crescentes
        ├── Decrescente/       # Outputs das entradas decrescentes
        ├── Desordenado-Ordenado/  # Outputs das entradas aleatórias
        └── log_memoria.dat    # Log de tempo e memória por execução
```

---

## Requisitos

- Python 3.8 ou superior
- Nenhuma dependência externa — apenas bibliotecas padrão (`math`, `time`, `os`, `tracemalloc`, `sys`)

---

## Como Executar

### Com Makefile (Linux)

```bash
# Executa o script (cria as pastas de saída automaticamente)
make

# Ou explicitamente
make run

# Remove todos os arquivos de saída gerados
make clean

# Exibe os alvos disponíveis
make help
```

### Sem Makefile

```bash
# A partir da raiz do projeto
python3 metodos_ordena.py
```

Os arquivos de saída serão gerados automaticamente em `dados/Saida/`.

---

## Entradas

Cada arquivo de entrada contém uma sequência de inteiros, um por linha, em três distribuições:

| Distribuição | Arquivos |
|---|---|
| Crescente | `input_crescente_10^2.dat` até `input_crescente_10^6.dat` |
| Decrescente | `input_decrescente_10^2.dat` até `input_decrescente_10^6.dat` |
| Aleatória | `input_random_10^2.dat` até `input_random_10^6.dat` |

---

## Saídas

Para cada arquivo de entrada, são gerados dois arquivos de saída — um para cada algoritmo — com o seguinte formato:

```
- Ordenacao Shell Sort:
- Tempo: 0.2274 segundos
- Total de elementos: 100000

[elementos ordenados, um por linha]
```

O arquivo `dados/Saida/log_memoria.dat` consolida o tempo e o pico de memória auxiliar de cada execução.

---

## Detalhes de Implementação

### Estrutura de dados

Utilizou-se a estrutura de lista nativa (`list`) do Python para o armazenamento dos elementos. Listas em Python são estruturas dinâmicas gerenciadas internamente como arrays de referências, que permitem acesso indexado em O(1) e troca direta de elementos — comportamento suficiente para algoritmos que operam exclusivamente por comparação e troca de posições.

### Medição de tempo

O tempo de execução é medido com `time.perf_counter()`, que oferece maior resolução temporal do que `time.time()`, sendo recomendado para medições de curta duração. A captura ocorre imediatamente antes e após a chamada ao algoritmo, excluindo leitura de arquivo e escrita dos resultados.

### Medição de memória

O consumo de memória auxiliar é mensurado via `tracemalloc`, capturando o pico de alocação exclusivamente durante a execução de cada algoritmo. A memória total do processo é capturada ao final de todas as execuções.

### Sequência de gaps — Shell Sort

Adotou-se a **sequência de Knuth (1973)**: gaps da forma (3^k − 1)/2, ou seja, 1, 4, 13, 40, 121, ... A sequência é calculada dinamicamente a partir do tamanho do vetor, encontrando o maior k tal que (3^k − 1)/2 < n, e decrementada a cada iteração até o gap final de valor 1.

### Fator de redução — Comb Sort

Adotou-se o fator de redução padrão de **1.3**, conforme proposto originalmente, que empiricamente apresenta bom desempenho na maioria das distribuições.

---

## Resultados Experimentais

### Tempo de execução

| n | Entrada | Shell Sort | Comb Sort |
|---|---|---|---|
| 10² | Aleatória | 178 µs | 221 µs |
| 10² | Crescente | 598 µs | 1 ms |
| 10² | Decrescente | 141 µs | 184 µs |
| 10³ | Aleatória | 20 ms | 10 ms |
| 10³ | Crescente | 15 ms | 10 ms |
| 10³ | Decrescente | 12 ms | 9 ms |
| 10⁴ | Aleatória | 268 ms | 180 ms |
| 10⁴ | Crescente | 91 ms | 261 ms |
| 10⁴ | Decrescente | 58 ms | 154 ms |
| 10⁵ | Aleatória | 1,422 s | 2,443 s |
| 10⁵ | Crescente | 936 ms | 1,815 s |
| 10⁵ | Decrescente | 690 ms | 1,709 s |
| 10⁶ | Aleatória | 23,325 s | 35,819 s |
| 10⁶ | Crescente | 6,533 s | 20,453 s |
| 10⁶ | Decrescente | 8,600 s | 23,192 s |

### Memória ocupada pela lista de entrada

| n | Memória |
|---|---|
| 10² | 4 KB |
| 10³ | 36 KB |
| 10⁴ | 357 KB |
| 10⁵ | 3.517 KB |
| 10⁶ | 35.594 KB |

A memória auxiliar dos algoritmos retornou **0 KB** em todos os casos, confirmando a natureza in-place e complexidade de espaço O(1) de ambos.

---

## Observações sobre Desempenho em Python

Os tempos observados refletem características inerentes à linguagem:

- **Linguagem interpretada**: o CPython executa via bytecode, acumulando overhead em laços intensos de comparação e troca.
- **Tipagem dinâmica**: cada comparação `lista[i] > lista[j]` exige resolução de tipo em tempo de execução.
- **Indireção de memória**: a `list` do Python não é um array contíguo de inteiros, mas uma sequência de ponteiros para objetos alocados dinamicamente no heap, com overhead de ~28 bytes por inteiro.

Em n = 10⁶ aleatório, o Shell Sort levou 23,325 s e o Comb Sort 35,819 s. O crescimento geral permanece subquadrático, consistente com a complexidade de pior caso O(n^(3/2)) do Shell Sort com sequência de Knuth, confirmando que o gargalo é o custo por operação do interpretador, e não a complexidade assintótica dos algoritmos.
