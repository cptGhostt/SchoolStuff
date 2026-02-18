import java.util.Arrays;

public class CumulatingSums {
    
    // vráti počet núl v stringovom zápise čísla retazec, ktoré prebehlo steps iteráciami vnútorného sčítania
    public static long pocetNul(String retazec, int steps) {
        int sum = 0;
        String s = cumulatingSum(retazec, steps);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') sum++;
        }
        return sum;
    }

    //vráti pole počtu číslic v stringovom zápise čísla retazec, ktoré prebehlo steps iteráciami vnútorného sčítania. Číslice, ktorých počty máte zisťovať, sú v poli cisla (vo výslednom poli vráťte počty číslic v poradí ako vo vstupnom poli)
    public static long[] pocet(String retazec, int steps, int[] cisla) {
        long[] sums = new long[cisla.length];
        String s = cumulatingSum(retazec, steps);
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < cisla.length; j++) {
                if (s.charAt(i) - '0' == cisla[j]) sums[j]++;
            }
        }

        return sums;
    }

    public static String cumulatingSum(String s, int n) {
        if (n == 0) return s;

        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < s.length()-1; j++) {
                sb.append(s.charAt(j));
                Integer sum = (s.charAt(j) - '0') + (s.charAt(j+1) - '0');
                sb.append(sum.toString());
            }
            sb.append(s.charAt(s.length()-1));
            s = sb.toString();
        }
        return s;
    }
}
