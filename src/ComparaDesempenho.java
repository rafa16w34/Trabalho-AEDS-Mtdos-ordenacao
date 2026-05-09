public class ComparaDesempenho {
    public static String testar(String entrada, String tipoDado) throws Exception {

        int[] numeros = GerenciaArquivos.ler(entrada);
        int tamanho = numeros.length;

        // salva na subpasta output
        String saidaShell = "data/output/output_shell_" + tipoDado + "_" + tamanho + ".dat";
        String saidaComb = "data/output/output_comb_" + tipoDado + "_" + tamanho + ".dat";

        int[] dadosShell = numeros.clone();
        int[] dadosComb = numeros.clone();

        // avaliação Shell Sort
        long inicioShell = System.nanoTime();
        ShellSort.ordenar(dadosShell);
        long fimShell = System.nanoTime();

        GerenciaArquivos.salvar(dadosShell, saidaShell);
        double tempoShell = (fimShell - inicioShell) / 1_000_000_000.0;

        // avaliação do Comb Sort
        long inicioComb = System.nanoTime();
        CombSort.ordenar(dadosComb);
        long fimComb = System.nanoTime();

        GerenciaArquivos.salvar(dadosComb, saidaComb);
        double tempoComb = (fimComb - inicioComb) / 1_000_000_000.0;

        System.out.printf("| %-15s | %-10d | %-15.6f | %-15.6f |\n", tipoDado, tamanho, tempoShell, tempoComb);

        return String.format("%-15s %-10d %-15.6f %-15.6f", tipoDado, tamanho, tempoShell, tempoComb);
    }
}