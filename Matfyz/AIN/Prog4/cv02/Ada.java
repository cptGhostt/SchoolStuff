public class Ada {
    public static int ageAL(){return 36;}

    public static double bernoulli(int n){
        if (n == 0) return 1.0;
        else if (n == 1) return -0.5;
        else if (n % 2 != 0) return 0.0;

        double ret = 0.0;
        for (int i=0; i<n; i++) {
            ret -= (double) binomial(n, i) * (bernoulli(i) / (double) (n - i + 1));
        }

        return ret;
    }

    public static long binomial(int n, int k)
    {
        long b = 1;
        for (int i=1, m=n; i<=k; i++, m--)
            b=b*m/i;
        return b;
    }

    public static void main(String[] args) {
        for (int a = 0; a < 9; a++) {
            System.out.println(bernoulli(a));
        }
    }
}
