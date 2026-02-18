public class Podobne {
    /**
     * vrati true ak pola na rovnakych miestach maju podobne hodnoty
     * retazec "aaa" je podobny cislu 3
     * retazec dlzky n samych a-cok je podobny cislu n
     * obsah poli moze byt lubovolny
     */
    public static boolean podobne(String[] a, Integer[] b) {
        if (a == null && b == null) return true;
        else if (a == null || b == null) return false;
        else if (a.length != b.length) return false;

        for (int i = 0; i < a.length; i++) {
            if (a[i] == null && b[i] == null) continue;
            else if (a[i] == null && b[i] != null) return false;
            else if (a[i] != null && b[i] == null) return false;

            int countOfA = (int) a[i].chars().filter(ch -> ch == 'a').count();

            // if (countOfA != a[i].length()) return false;
            if (countOfA != b[i]) return false;
        }

        return true; // toto asi nebude cele riesenie ....
    }

    public static void main(String[] args) {
        System.out.println(podobne(null, null));
        System.out.println(podobne(new String[]{"aa", null, ""}, new Integer[]{2, null, 0}));
        String[][] a = new String[][]{{"aa", null, ""}, {"a", "aa", "aaa"}, {}};
        Integer[][] b = new Integer[][]{{2, null, 0}, {1, 2, 3}};
        System.out.println(podobne2(a, b));
    }

    public static boolean podobne2(String[][] a, Integer[][] b) {
        if (a == null && b == null) return true;
        else if (a == null || b == null) return false;
        else if (a.length != b.length) return false;

        boolean control = true;
        for (int i = 0; i < a.length; i++) {
            control = podobne(a[i], b[i]);
            if (!control) return false;
        }
        return true; // ostra hra
    }
}