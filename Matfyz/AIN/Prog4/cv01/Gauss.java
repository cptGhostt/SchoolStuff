public class Gauss {

    public static long sucet(int from, int to)  {
        // return ((a+b) * (b-a+1) / 2);
        long a = from;
        long b = to;
        if ((a+b)%2 == 0){
            return ((a+b) / 2) * (b-a+1);
        } else if ((b-a+1) % 2 == 0) {
            return (a+b) * ((b-a+1) / 2);
        } else {
            return ((a+b) * (b-a+1) / 2);
        }
    }

    public static long sucet(int from, int to, int delta)  {
        if (delta == 1){
            return sucet(from, to);
        }

        long a = from;
        long b = to;

        long n = (b - a + 1) / delta;
        long sum;

        for (long i = b; i > a; i--){
            if ((i - a) % delta == 0){
                sum = a + i;
                return n * sum / 2;
            }
        }

        return a;

    }

    public static void main(String[] args){
        System.out.println(sucet(1, 100, 200));
    }


}