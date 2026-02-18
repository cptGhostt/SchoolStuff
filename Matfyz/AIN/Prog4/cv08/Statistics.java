import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Statistics {
    static final String url = "https://raw.githubusercontent.com/datasets/covid-19/master/data/countries-aggregated.csv?fbclid=IwAR2iKFpJVdryhZx5A6h_T66-eLZ0kcgciEbGxvZLdnQvW3b-fo2vvVvbiTY";

    private static Stream<String> fetch(String path) {
        try {
            BufferedReader read = new BufferedReader(
                new InputStreamReader(
                        new URL(path).openStream()));
            return read.lines();
        } catch (IOException e) {
            System.out.println("nieco zle sa stalo: " + e.getMessage());
            e.printStackTrace();
            return null;
        }
    }

    private static List<Integer> load(){
        List<String> lines = fetch(url).collect(Collectors.toList());
        List<Integer> values = new ArrayList<>();
        for (var line : lines) {
            String[] columns = line.split(",");
            try {
                int index = columns.length - 3;
                int count = Integer.parseInt(columns[index]);
                values.add(count);
            } catch(Throwable ee) {}
        }

        return values;
    }

    public static char najcastesia(){
        List<Integer> values = load();
        int[] p = new int[10];

        for (int value : values) {
            int c = Integer.toString(value).charAt(0) - '0';
            p[c]++;
        }

        int nc = 0;
        for(int i = 1; i < 10; i++){
            if(p[i] > p[nc]){
                nc = i;
            }
        }

        return (char) (nc + '0');
    }

    public static double pravdepodobnost(){
        List<Integer> values = load();
        int[] p = new int[10];

        for (int value : values) {
            int c = Integer.toString(value).charAt(0) - '0';
            p[c]++;
        }

        long sum = 0;
        for(int i = 1; i < 10; i++){
            sum += p[i];
        }

        double[] prav = new double[10];
        for(int i = 1; i < 10; i++){
            prav[i] = (double) p[i] / (double) sum;
        }

        double max = 0.0;
        for(int i = 0; i < 10; i++){
            if(prav[i] > max){
                max = prav[i];
            }
        }

        return max;
    }

    public static void main(String[] args) {
        List<Integer> values = load();
        System.out.println(values.get(53) + "==" + 20);
        System.out.println(najcastesia());
        System.out.println(pravdepodobnost());

    }
}
