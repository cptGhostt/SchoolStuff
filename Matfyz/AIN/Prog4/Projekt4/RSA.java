public class RSA extends Sifra {
    int N, e, d;

    public RSA() {
        int p, q;
        p = Main.PRIMES[(int) (Math.random() * Main.PRIMES.length)];
        do {
            q = Main.PRIMES[(int) (Math.random() * Main.PRIMES.length)];
        } while (p == q);

        N = p*q;
        int phi = (p-1)*(q-1);
        e = 2;

        while (GCD(phi, e) != 1) {
            e++;
        }
        d = modInverse(e, phi);

    }

    private int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    private int modInverse(int a, int b) {
        a %= b;
        for (int i = 1; i < b; i++) {
            if ((a*i)%b == 1) return i;
        }

        return 0;
    }

    @Override
    public String zasifruj(String sprava) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < sprava.length(); i++) {
            sb.append(((char)(Main.powMod(sprava.charAt(i), e, N))));
        }

        return sb.toString();
    }

    @Override
    public String desifruj(String sprava) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < sprava.length(); i++) {
            sb.append(((char)(Main.powMod(sprava.charAt(i), d, N))));
        }

        return sb.toString();
    }

    public int[] getPubKey(){
        return new int[]{N, e};
    }

    public String zasifrujCudzie(String sprava, int[] pubKey) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < sprava.length(); i++) {
            sb.append(((char)(Main.powMod(sprava.charAt(i), pubKey[1], pubKey[0]))));
        }

        return sb.toString();
    }
}
