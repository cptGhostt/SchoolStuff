public class CNN {
    public static long cnn(){
        for (long i = 10;;i++){
            if (isPrime(i) && isPalindrome(toBinary(i))){
                if (isPrime(mirror(i)) && isPalindrome(toBinary(mirror(i)))){
                    return i;
                }
            }
        }
    }

    public static boolean isPrime(long n){
        for(int i = 2; i <= n/2; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }

    public static long mirror(long n){
        long reverse = 0;
        while (n != 0){
            long tmp = n % 10;
            n /= 10;
            reverse = reverse * 10 + tmp;
        }
        return reverse;
    }

    public static String toBinary(long n){
        return Long.toBinaryString(n);
    }

    public static boolean isPalindrome(String s){
        for (int i = 0, j = s.length() - 1; i < j; i++, j--){
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args){
        System.out.println(cnn());
    }
}
