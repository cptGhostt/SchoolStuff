import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Teploty {
    List<Zaznam> riadky;

    public Teploty(String nazovSuboru) throws IOException {
        riadky = Files.lines(Path.of(nazovSuboru)).map(x -> {
            String[] vs = x.split(",");
            return new Zaznam(vs[0], vs[1], Double.parseDouble(vs[2]));
        }).collect(Collectors.toList());
    }

    public Map<String, Double> priemerneTeplotyVMestach() {
        return riadky.stream().collect(Collectors.groupingBy(Zaznam::getMesto, Collectors.averagingDouble(Zaznam::getHodnota))); // toto doprogramujte
    }

    public Map<String, Map<String, Long>> historgramyHodnotPreMesta() {
        return riadky.stream().collect(Collectors.groupingBy(Zaznam::getMesto, Collectors.groupingBy(
                                z -> {
                                    int spodna = ((int) Math.floor(z.getHodnota() / 10.0)) * 10;
                                    int horna = spodna + 10;
                                    return "[" + spodna + ", " + horna + "]";
                                },
                                Collectors.counting()))); // toto doprogramujte
    }

    // nepovinne, ale bolo by pekne riesit toto pomocou reduce
    public String mestoSNajnizsouTeplotou() {
        return riadky.stream().min(Comparator.comparingDouble(Zaznam::getHodnota)).map(Zaznam::getMesto).orElse(null); // toto doprogramujte
    }

    // nepovinne, ale bolo by pekne riesit toto collectorom
    public String mestoSNajvyssouTeplotou() {
        return riadky.stream().collect(Collectors.collectingAndThen(Collectors.maxBy(Comparator.comparingDouble(Zaznam::getHodnota)),
                opt -> opt.map(Zaznam::getMesto).orElse(null))); // toto dorpogramujte
    }

    public Map<String, Double[]> extremyVMestach() {
        return riadky.stream()
                .collect(Collectors.groupingBy(Zaznam::getMesto, Collector.of(() -> new double[]{Double.MAX_VALUE, -Double.MAX_VALUE},
                                (arr, z) -> {
                                    arr[0] = Math.min(arr[0], z.getHodnota());
                                    arr[1] = Math.max(arr[1], z.getHodnota());
                                },
                                (a1, a2) -> new double[]{
                                        Math.min(a1[0], a2[0]),
                                        Math.max(a1[1], a2[1])
                                },
                                arr -> new Double[]{arr[0], arr[1]}
                        )
                )); // toto doprogramujte
    }

    public Map<String, Set<String>> nadpriemerneHodnotyVMestach() {
        Map<String, Double> priemery = priemerneTeplotyVMestach();

        return riadky.stream().filter(z -> z.getHodnota() > priemery.get(z.getMesto())).collect(Collectors.groupingBy(
                        Zaznam::getMesto, Collectors.mapping(Zaznam::getId, Collectors.toSet()))); // toto doprogramujte
    }

    public static void main(String[] args) {
        try {
            Teploty z = new Teploty("data_temperatures.csv");
            System.out.println("Priemer:");
            System.out.println(z.priemerneTeplotyVMestach());
            System.out.println("Nadpriemerni:");
            System.out.println(z.nadpriemerneHodnotyVMestach());
            System.out.println("Histogram:");
            System.out.println(z.historgramyHodnotPreMesta());
            System.out.println("Mesto s najvyssou nameranou teplotou:");
            System.out.println(z.mestoSNajvyssouTeplotou());
            System.out.println("Mesto s najnizsou nameranou teplotou");
            System.out.println(z.mestoSNajnizsouTeplotou());
            System.out.println("Extremy v mestach");

            z.extremyVMestach().forEach((key, value) -> System.out.println("Mesto: " + key + " - min:" + value[0] + ", max: " + value[1]));

        } catch (IOException e) {
            System.err.println("au");
        }
    }
}
