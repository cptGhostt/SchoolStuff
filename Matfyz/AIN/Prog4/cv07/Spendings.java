import java.util.*;
import java.util.stream.Collectors;

public class Spendings {

    public static AbstractMap.SimpleEntry<String, Long> highest(List<AbstractMap.SimpleEntry<String, Long>> evidence)
    {
        Map<String, List<Long>> map = new HashMap<>();

        for (AbstractMap.SimpleEntry<String, Long> entry : evidence) {
            String key = entry.getKey();
            Long value = entry.getValue();

            if (map.containsKey(key)) {
                if (map.get(key).size() < 3) {
                    map.get(key).add(value);
                    map.put(key, map.get(key).stream().sorted(Comparator.reverseOrder()).collect(Collectors.toCollection(ArrayList::new)));
                }else {
                    if (map.get(key).get(2) < value) {
                        map.get(key).remove(2);
                        map.get(key).add(value);
                        map.put(key, map.get(key).stream().sorted(Comparator.reverseOrder()).collect(Collectors.toCollection(ArrayList::new)));
                    }
                }
            } else {
                map.put(key, new ArrayList<>());
                map.get(key).add(value);
            }
        }

        Map<String, Long> map2 = new HashMap<>();
        long maxValue = 0L;
        for (String key : map.keySet()) {
            long value = 0L;
            for (Long l : map.get(key)) {
                value += l;
            }

            if (value > maxValue) {
                map2.clear();
                map2.put(key, value);
                maxValue = value;
            }
            else if (value == maxValue) {
                map2.put(key, value);
            }
        }

        String[] tmp = map2.keySet().stream().sorted(Comparator.naturalOrder()).toArray(String[]::new);

        return new AbstractMap.SimpleEntry<>(tmp[0], map2.get(tmp[0]));
    }

    public static void main(String[] args) {
        List<AbstractMap.SimpleEntry<String, Long>> evidence1 = new ArrayList<>();
        evidence1.add(new AbstractMap.SimpleEntry<>("B", 20L));
        evidence1.add(new AbstractMap.SimpleEntry<>("A", 2L));
        evidence1.add(new AbstractMap.SimpleEntry<>("A", 10L));
        evidence1.add(new AbstractMap.SimpleEntry<>("A", 10L));
        evidence1.add(new AbstractMap.SimpleEntry<>("B", 30L));
        evidence1.add(new AbstractMap.SimpleEntry<>("A", 30L));

        System.out.println(highest(evidence1)); //A=50

        List<AbstractMap.SimpleEntry<String, Long>> evidence2 = new ArrayList<>();
        evidence2.add(new AbstractMap.SimpleEntry<>("central", 863L));
        evidence2.add(new AbstractMap.SimpleEntry<>("aupark", 393L));
        evidence2.add(new AbstractMap.SimpleEntry<>("eurovea", 161L));
        evidence2.add(new AbstractMap.SimpleEntry<>("aupark", 776L));
        evidence2.add(new AbstractMap.SimpleEntry<>("eurovea", 834L));
        evidence2.add(new AbstractMap.SimpleEntry<>("aupark", 713L));
        evidence2.add(new AbstractMap.SimpleEntry<>("eurovea", 791L));
        evidence2.add(new AbstractMap.SimpleEntry<>("aupark", 769L));
        evidence2.add(new AbstractMap.SimpleEntry<>("aupark", 777L));

        System.out.println(highest(evidence2)); //aupark=2322
    }
}
