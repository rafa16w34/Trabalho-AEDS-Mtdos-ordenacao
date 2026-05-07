public class ComparaDesempenho {
    public static void testar(String entrada, String tipoDado) throws Exception {

        // cria os arquivos finais
        String saidaShell = "data/output_shell_" + tipoDado + ".dat";
        String saidaComb = "data/output_comb_" + tipoDado + ".dat";

        // puxa todos os números do arquivo para a memória do programa
        int[] numeros = GerenciaArquivos.ler(entrada);

        // garante que ambos os algoritmos recebam a mesma lista para ordenar
        int[] dadosShell = numeros.clone();
        int[] dadosComb = numeros.clone();

        // avaliação shell sort
        long inicioShell = System.currentTimeMillis(); // dispara o cronômetro
        ShellSort.ordenar(dadosShell);                 // executa a ordenação
        long fimShell = System.currentTimeMillis();    // para o cronômetro

        // salva a lista ordenada no arquivo de saída
        GerenciaArquivos.salvar(dadosShell, saidaShell);

        double tempoShell = (fimShell - inicioShell) / 1000.0;
        System.out.printf("Tempo Shell Sort: %.3f segundos\n", tempoShell);

        // avaliação do combs sort
        long inicioComb = System.currentTimeMillis(); // inicia o cronômetro
        CombSort.ordenar(dadosComb);                  // ordenação
        long fimComb = System.currentTimeMillis();    // para o cronômetro

        // salva a lista ordenada no arquivo de saída
        GerenciaArquivos.salvar(dadosComb, saidaComb);

        double tempoComb = (fimComb - inicioComb) / 1000.0;
        System.out.printf("Tempo Comb Sort:  %.3f segundos\n", tempoComb);

    }
}