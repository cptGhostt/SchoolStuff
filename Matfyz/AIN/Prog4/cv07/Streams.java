import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Streams {
    /**
     * @return - vrati IntStream celych cisel poradi
     * n,
     * n,n-1,
     * n,n-1,n-2,
     * ... ,
     * n,n-1,n-2,...,3,2,1
     */
    public static IntStream pyramida(int n) {
        return IntStream.rangeClosed(1, n).flatMap(i -> IntStream.iterate(n, x -> x - 1).limit(i));  // doprogramuj
    }

    /**
     * @return - prefiltruje input stream a ponechá v ňom len čísla, ktorých dekadický zápis je symetrický,
     * tzv. palindromy (v tom istom poradí). Napríklad, 11, 121, 4224 sú palindromy a 12, 110 nie sú palindromy.
     */
    public static IntStream palindromy(IntStream input) {
        return input.filter(n -> n >= 0).filter(Streams::isPalindrome);  // doprogramuj
    }

    private static boolean isPalindrome(int n) {
        String s = Integer.toString(n);
        return s.equals(new StringBuilder(s).reverse().toString());
    }

    /**
     * @return - zo zoznamu cisel na vstup a vytvori mapu, ktora zobrazuje zlozene cislo zo vstupu na pocet
     * jeho delitelov medzi 2..n-1. Prvocisla na vstupe maju pocet delitelov 0, preto sa do mapy nezobrazuju
     */
    public static Map<Integer, Integer> pocetDelitelov(List<Integer> vstup) {
        return vstup.stream().filter(n -> n > 1 && !isPrime(n)).collect(Collectors.toMap(
                n -> n, Streams::countDivisors));
    }

    private static boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    private static int countDivisors(int n) {
        int count = 0;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) count++;
        }
        return count;
    }

    /**
     * @return pre vstupne cislo vyrobi mapu, ktora zobrazuje prvocislo, ktore ho deli, na exponent, ktory ma v
     * prvociselom rozklade. Priklad: pre 967032 = 2^3 * 3^3 * 11^2 * 37, mapa bude Map.of(2,3 3,3, 11,2, 37,1)
     */
    public static Map<Integer, Integer> rozklad(Integer vstup) {
        // s touto úlohou mi pomohol ChatGPT lebo nevedel som to urobiť cez streamy (vyzerá to tak že ani on nie)
        Map<Integer, Integer> faktory = new TreeMap<>();

        int n = vstup;
        for (int delitel = 2; delitel * delitel <= n; delitel++) {
            while (n % delitel == 0) {
                faktory.put(delitel, faktory.getOrDefault(delitel, 0) + 1);
                n /= delitel;
            }
        }

        if (n > 1) {
            faktory.put(n, faktory.getOrDefault(n, 0) + 1);
        }

        return faktory;
    }
}