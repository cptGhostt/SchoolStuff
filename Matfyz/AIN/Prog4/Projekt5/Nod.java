import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Nod<T extends Comparable<T>> implements Comparable<Nod<T>>, RTree<T>  {
    private T value;
    private List<Nod<T>> sons;

    // priklad rekurzie cez strom...
    public int size() {
        int count = 1;
        if (sons != null) {
            for (Nod<T> son : sons)
                if (son != null)
                    count += son.size();
        }
        return count;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(value);

        if (sons != null) {
            sb.append("(");
            for (int i = 0; i < sons.size(); i++){
                if (sons.get(i) != null) sb.append(sons.get(i).toString());
                if (i < sons.size() - 1){
                    sb.append(",");
                }
            }
            sb.append(")");
        }
        
        return sb.toString();
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }

    public List<Nod<T>> getSons() {
        return sons;
    }

    public void setSons(List<Nod<T>> sons) {
        this.sons = sons;
    }

    public Nod(T value, List<Nod<T>> sons) {
        this.value = value;
        this.sons = sons;
    }

    public boolean contains(T elem) {
        if (elem == null) return false;

        Stack<Nod<T>> stack = new Stack<>();
        stack.push(this);

        while (!stack.empty()) {
            Nod<T> nod = stack.pop();
            if (nod.value != null && nod.value.equals(elem)) return true;

            if (nod.sons != null) {
                for (Nod<T> son : nod.sons){
                    if (son != null) stack.push(son);
                }
            }
        }

        return false;
    }

    public boolean isLeaf(T elem) {
        if (elem == null) return false;

        Stack<Nod<T>> stack = new Stack<>();
        stack.push(this);

        while (!stack.isEmpty()) {
            Nod<T> nod = stack.pop();

            if (nod.sons == null || nod.sons.isEmpty()){
                if (nod.value != null && nod.value.equals(elem)) return true;
            } else {
                for (Nod<T> son : nod.sons) {
                    if (son != null) stack.push(son);
                }
            }
        }

        return false;
    }

    public List<T> preorder() {
        List<T> list = new ArrayList<>();
        Stack<Nod<T>> stack = new Stack<>();
        stack.push(this);

        while (!stack.isEmpty()) {
            Nod<T> nod = stack.pop();
            if (nod.value != null) list.add(nod.value);
            if (nod.sons != null) {
                for (int i = nod.sons.size() - 1; i >= 0; i--) {
                    if (nod.sons.get(i) != null) stack.push(nod.sons.get(i));
                }
            }
        }

        return list;
    }

    @Override
    public int compareTo(Nod<T> o) {
        if (o == null) return 1;
        if (this.value == null && o.value == null) return 0;
        if (this.value == null) return -1;
        if (o.value == null) return 1;

        if (this.value.compareTo(o.value) == 0){
            return this.sons.size() - o.sons.size();
        }
        return value.compareTo(o.value);
    }


    public static void main(String[] args) {
        Nod<String> n_dabc = new Nod<>("d",
                List.of(
                        new Nod<>("a", null),
                        new Nod<>("b", null),
                        new Nod<>("c", null))
        );
        Nod<String> n_efg = new Nod<>("e",
                List.of(
                        new Nod<>("f", null),
                        new Nod<>("g", null))
        );
        Nod<String> n_habcdefg = new Nod<>("h",
                List.of(
                        new Nod<>("d",
                              List.of(
                                        new Nod<>("a", null),
                                        new Nod<>("b", null),
                                        new Nod<>("c", null))
                        ),
                        new Nod<>("e",
                                List.of(
                                        new Nod<>("f", null),
                                        new Nod<>("g", null))
                        )));

        for(char ch : "abcdefghijkl".toCharArray()) {
            System.out.println(
                    "contains(" + ch + ")=" + n_habcdefg.contains(""+ch) +
                    "\t isList(" + ch + ")=" + n_habcdefg.isLeaf(""+ch)

            );
        }
        System.out.println(n_habcdefg);
        System.out.println(n_dabc);
        System.out.println(n_efg);
        System.out.println(n_habcdefg.preorder());
        System.out.println(n_habcdefg.compareTo(n_habcdefg));
        System.out.println(n_habcdefg.compareTo(n_dabc));
        System.out.println(n_habcdefg.compareTo(n_efg));
        System.err.println("error");
    }
}
