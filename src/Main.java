import java.io.File;
import java.io.PrintWriter;

public class Main {

    public static void main(String[] args) throws Exception {

        // cria o arquivo de resultados na pasta data
        PrintWriter escritor = new PrintWriter(new File("data/resultados.dat"));

        escritor.println("TIPO         TAMANHO    SHELL_SORT(s)   COMB_SORT(s)");

        System.out.println("+-----------------+------------+-----------------+-----------------+");
        System.out.println("| Cenário         | Tamanho    | Shell Sort (s)  | Comb Sort (s)   |");
        System.out.println("+-----------------+------------+-----------------+-----------------+");

        String[] arquivosAleatorios = {
                "data/input/input_random_10^2.dat",
                "data/input/input_random_10^3.dat",
                "data/input/input_random_10^4.dat",
                "data/input/input_random_10^5.dat",
                "data/input/input_random_10^6.dat"
        };

        for (String arquivo : arquivosAleatorios) {
            String linha = ComparaDesempenho.testar(arquivo, "Aleatorio");
            escritor.println(linha);
        }

        System.out.println("+-----------------+------------+-----------------+-----------------+");

        String[] arquivosCrescentes = {
                "data/input/input_crescente_10^2.dat",
                "data/input/input_crescente_10^3.dat",
                "data/input/input_crescente_10^4.dat",
                "data/input/input_crescente_10^5.dat",
                "data/input/input_crescente_10^6.dat"
        };

        for (String arquivo : arquivosCrescentes) {
            String linha = ComparaDesempenho.testar(arquivo, "Crescente");
            escritor.println(linha);
        }

        System.out.println("+-----------------+------------+-----------------+-----------------+");

        String[] arquivosDecrescentes = {
                "data/input/input_decrescente_10^2.dat",
                "data/input/input_decrescente_10^3.dat",
                "data/input/input_decrescente_10^4.dat",
                "data/input/input_decrescente_10^5.dat",
                "data/input/input_decrescente_10^6.dat"
        };

        for (String arquivo : arquivosDecrescentes) {
            String linha = ComparaDesempenho.testar(arquivo, "Decrescente");
            escritor.println(linha);
        }

        System.out.println("+-----------------+------------+-----------------+-----------------+");

        escritor.close();
    }
}