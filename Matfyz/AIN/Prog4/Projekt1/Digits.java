public class Digits {

    public static int calculate(int k, int b) {
        if (k == 1) return b;

        boolean[] visited = new boolean[9];
        return (find(visited, k, b, 0, 0));
    }

    public static int find(boolean[] visited, int k, int b, int current, int sum) {
//        if (k == 0){
//            return (factor(sum) == b) ? current : -1;
//        }

        for (int i = 0; i < 9; i++) {
            if (visited[i]) continue;

            int newSum = sum + (i + 1);

            if (k == 1) {
                if (factor(newSum) == b) return current*10 + i+1;
                else continue;
            }

            visited[i] = true;
            int match = (find(visited, k-1, b, current*10 + i+1, newSum));
            visited[i] = false;
            if (match != -1) return match;
        }

        return -1;
    }

    public static int factor(int n) {
        while (n > 9) {
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            n = sum;
        }
        return n;
    }

    public static void main(String[] args) {
        System.out.println(calculate(3, 6));
    }
}
