import org.junit.Test;
import java.util.*;


import static org.junit.Assert.assertEquals;

public class TestSums {
    public Long getRandomNumber(int min, int max) {
        return (long) ((Math.random() * (max - min)) + min);
    }

    @Test
    public void testSums() {
        Sums sums = new Sums();

        List<Long> allValues = new ArrayList<>(100);
        for (int i = 1; i < 10; i++) {
            List<Long> newValues = new ArrayList<>(10);
            for (int j = 0; j < 10; j++) {
                newValues.add(getRandomNumber(1, 100));
            }

            allValues.addAll(newValues);
            Collections.shuffle(newValues);
            sums.addNewValues(newValues);
        }

        assertEquals("Sums: values=" + allValues,
                allValues.stream().sorted(Comparator.reverseOrder()).limit(3).mapToLong(Long::longValue).sum(),
                sums.top3());

        sums = new Sums();

        for (int i = 1; i < 1_000; i++) {

            List<Long>newValues = new ArrayList<>(5_000);
            for (int j = 0; j < 5_000; j++) {
                newValues.add(getRandomNumber(1, 10));
            }

            long sum = 0;
            for (int j = 0; j < 3; j++) {
                long num = 11 * i;
                newValues.add(num);
                sum = sum + num;
            }

            Collections.shuffle(newValues);
            sums.addNewValues(newValues);

            assertEquals("Sums: newValues=" + newValues,
                    sum,
                    sums.top3());
        }
    }
}
