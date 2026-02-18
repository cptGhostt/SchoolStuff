import java.util.*;

public class FaceHook<E> {
    Map<E, Set<E>> map;

    public FaceHook() {
        map = new HashMap<>();
    }

    public void blizkiPriatelia(E meno1, E meno2) {
        if (meno1.equals(meno2)) return;

        if (!map.containsKey(meno1)) {
            map.put(meno1, new HashSet<>());
        }
        if (!map.containsKey(meno2)) {
            map.put(meno2, new HashSet<>());
        }

        map.get(meno1).add(meno2);
        map.get(meno2).add(meno1);
    }

    public Set<E> vsetci() { return map.keySet(); }

    public int pocetPriatelov(E meno) {
        if (!map.containsKey(meno)) return 0;

        return map.get(meno).size();
    }

    public int spolocniPriatelia(E meno1, E meno2) {
        if (!map.containsKey(meno1)) return 0;
        if (!map.containsKey(meno2)) return 0;

        Set<E> tmp = new HashSet<>();

        for (E e : map.get(meno1)) {
            if (map.get(meno2).contains(e)) tmp.add(e);
        }

        return tmp.size();

    }

    public boolean vzdialenyPriatel(E meno1, E meno2) {
        if (!map.containsKey(meno1)) return false;
        if (!map.containsKey(meno2)) return false;

        Stack<E> stack = new Stack<>();
        Set<E> visited = new HashSet<>();
        stack.push(meno1);
        visited.add(meno1);

        while (!stack.isEmpty()) {
            E e = stack.pop();
            for (E ee : map.get(e)) {
                if (!visited.contains(ee)) {
                    if (ee.equals(meno2)) return true;
                    stack.push(ee);
                    visited.add(ee);
                }
            }
        }

        return false;
    }

    @Override
    public String toString() {
        return map.toString();
    }

    public static void main(String[] args) {
        {   // FaceHook<String>
            FaceHook<String> fk = new FaceHook<>();
            fk.blizkiPriatelia("a", "b");
            fk.blizkiPriatelia("a", "c");
            fk.blizkiPriatelia("e", "f");
            System.out.println(fk);                                  // nejaká reprezentacia grafu
            System.out.println(fk.vsetci());                         // nejaká permutácia "a","b","c","e","f"
            System.out.println(fk.pocetPriatelov("c"));        // 1
            System.out.println(fk.pocetPriatelov("a"));        // 2
            System.out.println(fk.spolocniPriatelia("b", "c"));     // 1
            System.out.println(fk.vzdialenyPriatel("b", "c"));      // true
            System.out.println(fk.vzdialenyPriatel("a", "e"));      // false
        }
        {   // FaceHook<Objekt>
            FaceHook<Objekt> fk = new FaceHook<>();
            Objekt a = new Objekt("a"); Objekt aa = new Objekt("a");
            Objekt b = new Objekt("b"); Objekt bb = new Objekt("b");
            Objekt c = new Objekt("c"); Objekt cc = new Objekt("c");
            Objekt d = new Objekt("d"); Objekt dd = new Objekt("d");
            Objekt e = new Objekt("e"); Objekt ee = new Objekt("e");
            Objekt f = new Objekt("f"); Objekt ff = new Objekt("f");

            fk.blizkiPriatelia(a, b);
            fk.blizkiPriatelia(a, c);
            fk.blizkiPriatelia(e, f);
            System.out.println(fk);                                 // nejaká reprezentacia grafu
            System.out.println(fk.vsetci());                        // nejaká permutácia "a","b","c","e","f"
            System.out.println(fk.pocetPriatelov(cc));              // 1
            System.out.println(fk.pocetPriatelov(aa));              // 2
            System.out.println(fk.spolocniPriatelia(bb, cc));       // 1
            System.out.println(fk.vzdialenyPriatel(bb, cc));        // true
            System.out.println(fk.vzdialenyPriatel(aa, ee));        // false
        }
    }
}
