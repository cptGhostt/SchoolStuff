import java.util.*;

public class Ones {

    public static Integer [] process(int N, List<AbstractMap.SimpleEntry<Integer, Integer>> queries) {
        List<Integer> toReturn = new ArrayList<>();
        Integer [] a = new Integer[N];
        TreeSet<Integer> indexes = new TreeSet<>();

        for (AbstractMap.SimpleEntry<Integer, Integer> query : queries) {
            int key = query.getKey();
            int value = query.getValue();


            if (key == 1) {
                try {
                    a[value] = 1;
                    indexes.add(value);
                } catch (Exception e) {}
            }
            else if (key == 2) {
                Integer index = indexes.ceiling(value);
                if (index != null) {
                    toReturn.add(index.intValue());
                } else {
                    toReturn.add(-1);
                }
            }
        }

        int f = toReturn.size();
        return toReturn.toArray(new Integer[f]);
    }

    public static void main(String[] args) {
        int N = 5;
        List<AbstractMap.SimpleEntry<Integer, Integer>> queries = new ArrayList<>();
        queries.add(new AbstractMap.SimpleEntry<>(2, 2));
        queries.add(new AbstractMap.SimpleEntry<>(1, 1));
        queries.add(new AbstractMap.SimpleEntry<>(2, 0));
        queries.add(new AbstractMap.SimpleEntry<>(2, 2));
        queries.add(new AbstractMap.SimpleEntry<>(2, 1));

        System.out.println(Arrays.toString(process(N, queries))); //[-1, 1, -1, 1]
    }
}
