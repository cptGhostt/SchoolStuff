import java.util.*;
import java.util.stream.*;

public class Streams {
    public static IntStream striedavo(int n) {
        return IntStream.range(0,2*n+1).map(x -> (x % 2 == 0) ? x/2 : -(x+1)/2);
    }

    public static boolean jeprvocislo(int n){
        if (n <= 1) return false;
        return IntStream.range(2,1 + (int) Math.sqrt(n)).noneMatch(x -> n % x == 0);
    }

    public static IntStream prvocisla(IntStream input) {
        return input.filter(x -> jeprvocislo(x));
    }

    public static Map<Integer, Long> najvyssiaCifra(List<Integer> vstup) {
        return vstup.stream().map(x->String.valueOf(x).charAt(0) - '0').collect(Collectors.toMap(x -> x,x->1L, Long::sum));
    }

    public static List<Integer> delitele(int n){
        return IntStream.range(1,n+1).filter(x -> n % x == 0).boxed().collect(Collectors.toList());
    }

    public static Map<Integer, List<Integer>> delitele(IntStream input) {
        return input.mapToObj(x-> new AbstractMap.SimpleEntry<Integer,List<Integer>>(x,delitele(x))).collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    public static void main(String[] args) {
        striedavo(10).forEach(x->System.out.print(x+" "));
        System.out.println();
        prvocisla(IntStream.of(0,1,2,3,4,5,6,7,8,9,10,11,47,49)).forEach(x->System.out.print(x+" "));
        System.out.println();
        System.out.println(najvyssiaCifra(List.of(2,3,22,33,55,1728,1729)).entrySet());
        System.out.println(delitele(IntStream.of(0,1,2,3,4,8,12,24,32,47,49)));
    }
}
