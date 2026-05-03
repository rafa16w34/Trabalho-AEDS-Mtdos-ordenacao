public class Main {

    public static void main(String[] args) throws Exception {

        String entrada = "data/input_random.dat";
        String saidaShell = "data/output_shell.dat";
        String saidaComb = "data/output_comb.dat";

        // faz a leitura dos números da entrada através da função de leitura
        int[] numeros = GerenciaArquivos.ler(entrada);

        // faz um clone dos dados para nao ocorrer problemas na comparação
        int[] dadosShell = numeros.clone();
        int[] dadosComb = numeros.clone();

        // cronometra o tempo que o algoritmo gasta para a ordenação
        long inicioShell = System.currentTimeMillis();

        //faz a ordenação
        ShellSort.ordenar(dadosShell);

        long fimShell = System.currentTimeMillis();

        // salvando os numeros ordenados
        GerenciaArquivos.salvar(dadosShell, saidaShell);

        // calcula o tempo total em segundos
        double tempoSegundosShell = (fimShell - inicioShell) / 1000.0;

        System.out.println("Tempo de execucao Shell Sort: " + tempoSegundosShell + " segundos");

        // cronometra o tempo que o algoritmo gasta para a ordenação
        long inicioComb = System.currentTimeMillis();

        //faz a ordenação
        CombSort.ordenar(dadosComb);

        long fimComb = System.currentTimeMillis();

        // salvando os numeros ordenados
        GerenciaArquivos.salvar(dadosComb, saidaComb);

        // calcula o tempo total em segundos
        double tempoSegundosComb = (fimComb - inicioComb) / 1000.0;

        System.out.println("Tempo de execucao Comb Sort: " + tempoSegundosComb + " segundos");
    }
}