# Trabalho-AEDS-Mtdos-ordenacao
Trabalho em grupo sobre metodos de ordenação

## Relatório Rafael:

O desenvolvimento do projeto teve início com a implementação, em C++, do algoritmo de ordenação Shell Sort, juntamente com funções auxiliares para leitura de dados a partir de arquivos. Para validação inicial, foi utilizado um conjunto de dados contendo 10⁶ elementos, armazenados em um arquivo previamente gerado por inteligência artificial (GPT), composto por números inteiros de 1 a 10⁶ dispostos de forma aleatória.

O código foi estruturado de forma modular, com separação das responsabilidades em diferentes arquivos, e posteriormente compilado em um executável (main.exe) por meio do terminal bash do Visual Studio Code.

Após a verificação da corretude da ordenação, foi implementada uma função responsável por escrever os dados ordenados em um arquivo de saída (output.dat). Paralelamente, foi incorporada a biblioteca <chrono>, com o objetivo de medir o tempo de execução do algoritmo. Nessa etapa, observou-se um tempo médio de aproximadamente 2,8 segundos para a ordenação completa, valor considerado elevado para a linguagem C++ e para o volume de dados utilizado.

Diante disso, foi realizada uma análise da implementação, com foco na função de ordenação. Inicialmente, os valores de gap eram calculados utilizando a abordagem clássica gap=n/2, sendo sucessivamente reduzidos pela metade. Após pesquisa teórica, verificou-se que o desempenho do Shell Sort está diretamente relacionado à escolha da sequência de gaps, e que sequências mais eficientes podem ser obtidas a partir da fórmula:

<div align="center">

<img width="227" height="97" alt="Image" src="https://github.com/user-attachments/assets/e73a30c2-9922-40ed-9b9b-b991c5dd51a1" />

</div>

<div align="justify">

(Onde h representa o valor do gap e k o índice da sequência. Essa formulação corresponde à sequência proposta por Knuth, amplamente utilizada por apresentar melhor desempenho prático. *1)

A implementação dessa nova abordagem exigiu a reformulação da lógica de cálculo dos gaps. As primeiras tentativas apresentaram inconsistências, principalmente devido ao uso inadequado da função pow para gerar os valores da sequência e à combinação incorreta entre diferentes estratégias de redução do gap, como a mistura entre a sequência de Knuth e a divisão sucessiva por 2. Essas abordagens resultaram em uma sequência de gaps não ideal, prejudicando a eficiência do algoritmo, uma vez que não promoviam uma pré-ordenação adequada dos dados, aumentando o custo das etapas finais do processo.

Diante dessas limitações, foi adotada uma implementação baseada integralmente na sequência de Knuth, na qual os gaps são gerados iterativamente pela relação h=3h+1 até o maior valor válido menor que n/3, e posteriormente percorridos de forma decrescente pela relação inversa h=(h−1)/3. Essa abordagem apresenta vantagens importantes, como a eliminação do uso de operações com ponto flutuante, a adaptação dinâmica ao tamanho do vetor e, principalmente, uma melhor distribuição dos elementos ao longo das iterações, o que reduz significativamente o trabalho necessário nas etapas finais do algoritmo (equivalentes a um insertion sort com gap=1).

Apesar da adoção dessa estratégia mais eficiente e da melhoria na organização dos dados durante o processo de ordenação, o tempo de execução ainda se mostrava insatisfatório, mantendo-se em torno de 2 segundos em diferentes execuções.

Posteriormente, foi identificado que a operação de escrita em arquivo (output.dat) introduzia um custo significativo ao tempo total de execução, uma vez que operações de entrada e saída (I/O) possuem custo elevado quando comparadas a operações em memória. Considerando que o objetivo principal do experimento era avaliar o desempenho do algoritmo de ordenação, e que sua correção já havia sido validada, optou-se pela remoção da função de escrita de dados.

Com essa modificação, observou-se uma melhora expressiva no desempenho, com o tempo de execução reduzido para aproximadamente 0,8 segundos, representando uma diminuição superior a 70% em relação à versão inicial.

Posteriormente, optei por manter a escrita dos dados no arquivo de saída (output.dat). No entanto, diferentemente da abordagem inicial, o tempo de execução passou a ser medido apenas até o término da ordenação, ou seja, o contador é finalizado antes da chamada da função de escrita. Dessa forma, a operação de saída não interfere na análise de desempenho do algoritmo Shell Sort.

Além disso, o início da medição de tempo foi ajustado para ocorrer somente após a leitura completa do arquivo de entrada, garantindo que a função de leitura também não impactasse os resultados obtidos. Para aumentar a confiabilidade dos testes, as execuções passaram a ser realizadas com o mínimo de processos em segundo plano, mantendo apenas a IDE aberta, de modo a reduzir o consumo de CPU e memória por outros aplicativos.
Com essas melhorias metodológicas, o tempo de execução do Shell Sort apresentou uma redução adicional de aproximadamente 60%, passando de cerca de 0,8 segundos para 0,6 segundos.

Após a estabilização e validação do Shell Sort, iniciou-se a implementação do algoritmo Comb Sort. Paralelamente, foram criadas funções auxiliares para iniciar e encerrar a medição de tempo, com o objetivo de tornar o fluxo do programa mais organizado e reutilizável.
Durante a compilação, foi identificado um erro relacionado ao uso do tipo auto em parâmetros de função, recurso disponível apenas a partir do padrão C++20. Para contornar essa limitação, o código passou a ser compilado com a flag:

<div align="center">

```g++ -std=c++20 src/*.cpp -o main```

</div>

<div align="justify">

Após essas modificações, foi possível obter os tempos de execução do Comb Sort. Os resultados indicaram um tempo médio de aproximadamente 0,68 segundos, ligeiramente inferior ao do Shell Sort. Especificamente, o Shell Sort apresentou tempo médio de 693 milissegundos, enquanto o Comb Sort obteve 678,8 milissegundos, configurando uma diferença de poucos milissegundos, porém consistente em múltiplas execuções.

##

*1 : https://www.youtube.com/watch?v=N5flk53THTo&t=638s

