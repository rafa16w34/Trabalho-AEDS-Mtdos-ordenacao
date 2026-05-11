public class ShellSort {

    public static void ordenar(int[] arr) {
        int n = arr.length;
        int gap = 1;

        // calcula o gap máximo inicial segundo a sequência de Knuth, a fórmula é h = 3h + 1
        while (gap < n / 3) {
            gap = 3 * gap + 1;
        }

        // começa a ordenação e vai diminuindo o gap até chegar a 1
        while (gap > 0) {

            // lógica do Insertion Sort para os elementos na distância do 'gap'
            for (int i = gap; i < n; i++) {

                int temp = arr[i];
                int j = i;

                // compara o valor guardado com os elementos anteriores do mesmo subgrupo
                while (j >= gap && arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap; // volta o índice de acordo com o gap
                }

                // insere o valor salvo na posição correta encontrada
                arr[j] = temp;
            }

            // reduz o gap para o próximo ciclo fazendo a fórmula inversa
            gap = (gap - 1) / 3;
        }
    }
}