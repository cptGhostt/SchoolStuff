import java.util.ArrayList;

public class Rozklad {

    public static long rozklad(int a, int b) {
        ArrayList<Long> arr = new ArrayList<>();
        for (long i = a; i <= b; i++) {
            arr.add(i);
        }
        return rek(arr, new ArrayList<>(), new ArrayList<>());
    }

    private static long rek(ArrayList<Long> arr, ArrayList<Long> arr1, ArrayList<Long> arr2) {
        if (arr.isEmpty()) {
            long sum1 = sum(arr1);
            long sum2 = sum(arr2);
            long prod1 = product(arr1);
            long prod2 = product(arr2);

            if (sum1 < sum2 && prod1 > prod2) return sum1 * prod2;
            if (sum2 < sum1 && prod2 > prod1) return sum2 * prod1;
            return -1;
        }

        long last = arr.remove(arr.size() - 1);

        arr1.add(last);
        long res1 = rek(arr, arr1, arr2);
        arr1.remove(arr1.size() - 1);

        arr2.add(last);
        long res2 = rek(arr, arr1, arr2);
        arr2.remove(arr2.size() - 1);

        arr.add(last);

        if (res1 == -1) return res2;
        if (res2 == -1) return res1;
        return Math.min(res1, res2);
    }

    private static long sum(ArrayList<Long> list) {
        long sum = 0;
        for (long num : list) sum += num;
        return sum;
    }

    private static long product(ArrayList<Long> list) {
        long prod = 1;
        for (long num : list) prod *= num;
        return prod;
    }
    public static void main(String[] args) {
        System.out.println(rozklad(1, 6));
        System.out.println(rozklad(6, 12));
        System.out.println(rozklad(5, 15));
    }

}
