import java.util.HashSet;

public class Alternating {

    public static int alternate(String str) {
        if (str.length() < 2) return str.length();
        if (str.length() == 2 && str.charAt(0) != str.charAt(1)) return 2;
        if (str.length() == 2) return 0;

        HashSet<Character> uniqueChars = new HashSet<Character>();
        for (int i = 0; i < str.length(); i++) {
            uniqueChars.add(str.charAt(i));
        }
        Character[] chars = uniqueChars.toArray(new Character[0]);

        int toReturn = 0;
        for (int i = 0; i < chars.length; i++) {
            for (int j = i + 1; j < chars.length; j++) {
                int tmp = findString(str, chars[i], chars[j]);
                if (tmp > toReturn) toReturn = tmp;
            }
        }


        return toReturn;
    }

    private static int findString (String s, char a, char b) {
        int len = 0;
        char last = '\0';

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == a || s.charAt(i) == b) {
                if (s.charAt(i) == last) return -1;

                last = s.charAt(i);
                len++;
            }
        }

        return len;
    }

    public static void main(String[] args) {
        System.out.println(alternate("abaacdabd"));
        System.out.println(alternate("ehdehhihde"));
        System.out.println(alternate("cd"));
        System.out.println(alternate("eeeeeeeeeeeeeeeee"));
    }
}
