import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class GerenciaArquivos {

    // lê o arquivo input
    public static int[] ler(String caminho) throws Exception {
        Scanner leitor = new Scanner(new File(caminho));
        ArrayList<Integer> lista = new ArrayList<>();

        // lê linha por linha
        while (leitor.hasNextInt()) {
            lista.add(leitor.nextInt());
        }
        leitor.close();

        // pega a lista e transforma num array
        int[] arrayDeNumeros = new int[lista.size()];
        for (int i = 0; i < lista.size(); i++) {
            arrayDeNumeros[i] = lista.get(i);
        }

        return arrayDeNumeros;
    }

    // salva o arquivo
    public static void salvar(int[] dados, String caminho) throws Exception {
        PrintWriter escritor = new PrintWriter(new File(caminho));

        // passa por todos os números ordenados e escreve um em cada linha
        for (int i = 0; i < dados.length; i++) {
            escritor.println(dados[i]);
        }

        escritor.close();
    }
}