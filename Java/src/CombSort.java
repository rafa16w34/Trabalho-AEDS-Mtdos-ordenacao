public class CombSort {

    public static void ordenar(int[] arr) {
        int n = arr.length;
        int gap = n;
        boolean trocou = true;

        // o loop continua enquanto o gap for maior que 1 ou enquanto houver trocas acontecendo
        while (gap > 1 || trocou) {

            // calcula o próximo gap dividindo pelo fator de encolhimento
            gap = (int) (gap / 1.3);

            //gap mínimo
            if (gap < 1) {
                gap = 1;
            }

            trocou = false;

            // percorre o array comparando os elementos separados pela distância do gap
            for (int i = 0; i < n - gap; i++) {
                if (arr[i] > arr[i + gap]) {
                    // se o elemento da esquerda for maior inverte os dois de lugar
                    int temp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = temp;

                    // sinaliza que ocorreu uma troca
                    trocou = true;
                }
            }
        }
    }
}