public class ShellSort {

    public static void ordenar(int[] arr) {
        int n = arr.length;

        // o algoritmo divide o array em subgrupos separados por um intervalo (gap).
        // o gap começa sendo a metade do array e é dividido por 2 a cada ciclo, até chegar a 1.
        for (int gap = n / 2; gap > 0; gap /= 2) {

            // lógica do Insertion Sort para os elementos que estão na distância do 'gap'.
            for (int i = gap; i < n; i++) {

                int temp = arr[i]; // variável auxiliar para guardar o valor
                int j;

                // compara o valor guardado com os elementos anteriores do mesmo subgrupo.
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }

                // Insere o valor salvo na posição correta encontrada.
                arr[j] = temp;
            }
        }
    }
}