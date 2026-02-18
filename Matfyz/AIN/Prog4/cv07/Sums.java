import java.util.*;
import java.util.stream.Collectors;

public class Sums {

    List<Long> values = new ArrayList<>(3);

    void addNewValues(List <Long> newValues) {
        for (Long newValue : newValues) {
            if (values.size() < 3) {
                values.add(newValue);
                values = values.stream().sorted(Comparator.reverseOrder()).collect(Collectors.toCollection(ArrayList::new));
            } else {
                if (values.get(2) < newValue) {
                    values.remove(2);
                    values.add(newValue);
                    values = values.stream().sorted(Comparator.reverseOrder()).collect(Collectors.toCollection(ArrayList::new));
                }
            }
        }
    }

    long top3() {
        return values.get(0) + values.get(1) + values.get(2);
    }

    public static void main(String[] args) {
        Sums sums = new Sums();

        sums.addNewValues(new ArrayList<>(List.of(1L, 2L, 3L)));
        sums.addNewValues(new ArrayList<>(List.of(1L, 2L, 3L)));
        System.out.println(sums.top3()); //8

        sums.addNewValues(new ArrayList<>(List.of(10L, 10L)));
        System.out.println(sums.top3()); //23

        List<Long> newValues = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            newValues.add((long) i);
        }
        Collections.shuffle(newValues);
        sums.addNewValues(newValues);

        System.out.println(sums.top3()); //97 + 98 + 99 = 294
    }
}
