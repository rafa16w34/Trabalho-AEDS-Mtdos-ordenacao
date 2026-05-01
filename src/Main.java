public class Main {

    public static void main(String[] args) throws Exception {

        String entrada = "data/input_random.dat";
        String saida = "data/output.dat";

        // faz a leitura dos números da entrada através da função de leitura
        int[] numeros = GerenciaArquivos.ler(entrada);

        System.out.println("2. Ordenando " + numeros.length + " números...");

        // cronometra o tempo que o algoritmo gasta para a ordenação
        long inicio = System.currentTimeMillis();

        //faz a ordenação
        ShellSort.ordenar(numeros);

        long fim = System.currentTimeMillis();

        // salvando os numeros ordenados
        GerenciaArquivos.salvar(numeros, saida);

        // calcula o tempo total em segundos
        double tempoSegundos = (fim - inicio) / 1000.0;

        System.out.println("Tempo de execucao: " + tempoSegundos + " segundos");
    }
}