public class ComparaDesempenho {
    public static String testar(String entrada, String tipoDado) throws Exception {

        int[] numeros = GerenciaArquivos.ler(entrada);
        int tamanho = numeros.length;
        long memObjetos = (tamanho * 4) / 1024;

        int[] dadosShell = numeros.clone();
        int[] dadosComb = numeros.clone();

        Runtime runtime = Runtime.getRuntime();

        runtime.gc(); // Limpa o lixo da leitura do arquivo
        long memAntesShell = runtime.totalMemory() - runtime.freeMemory();

        long inicioShell = System.nanoTime();
        ShellSort.ordenar(dadosShell);
        long fimShell = System.nanoTime();

        long memDepoisShell = runtime.totalMemory() - runtime.freeMemory();
        long memGastaShell = Math.max(0, (memDepoisShell - memAntesShell) / 1024);

        runtime.gc(); // Limpa qualquer lixo que o Shell tenha deixado
        long memAntesComb = runtime.totalMemory() - runtime.freeMemory();

        long inicioComb = System.nanoTime();
        CombSort.ordenar(dadosComb);
        long fimComb = System.nanoTime();

        long memDepoisComb = runtime.totalMemory() - runtime.freeMemory();
        long memGastaComb = Math.max(0, (memDepoisComb - memAntesComb) / 1024);

        double tempoShell = (fimShell - inicioShell) / 1000.0;
        double tempoComb = (fimComb - inicioComb) / 1000.0;

        System.out.println(tamanho + " - " + tipoDado);
        System.out.printf("Tempo Shell Sort:  %.0f us\n", tempoShell);
        System.out.printf("Tempo Comb Sort:   %.0f us\n", tempoComb);
        System.out.println("Memoria Shell Sort: " + memGastaShell + " KB");
        System.out.println("Memoria Comb Sort:  " + memGastaComb + " KB");
        System.out.println("Memoria utilizada pelos objetos: " + memObjetos + " KB\n");

        return String.format("%-15s %-10d %-15.0f %-15.0f %-10d", tipoDado, tamanho, tempoShell, tempoComb, memObjetos);
    }
}