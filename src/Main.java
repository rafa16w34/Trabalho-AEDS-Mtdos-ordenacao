public class Main {

    public static void main(String[] args) throws Exception {

        System.out.println("Tipo de Dado: Aleatorio");
        ComparaDesempenho.testar("data/input_random.dat", "aleatorio");

        System.out.println("\n==================================================");
        System.out.println("Tipo de dado: Crescente (Ordenado)");
        ComparaDesempenho.testar("data/input_sorted.dat", "crescente");

        System.out.println("\n==================================================");
        System.out.println("Tipo de dado: Decrescente (Ordenado)");
        ComparaDesempenho.testar("data/input_sorted_desc.dat", "decrescente");
    }
}