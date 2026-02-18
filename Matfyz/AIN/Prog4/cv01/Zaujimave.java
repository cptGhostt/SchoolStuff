public class Zaujimave {
    public static int pocetZaujimavychInt(int n) {
        if (n % 10 == 9){
            return n/10 + 1;
        }
        return n/10;
    }

    public static long pocetZaujimavychLong(long n) {
        if (n % 10 == 9){
            return n/10 + 1;
        }
        return n/10;
    }
    
    public static long pocetBinarneZaujimavychLong(long n) {
        if (n % 4 == 3){
            return n/4 + 1;
        }
        return n/4;
    }
    
    public static void main(String[] args) {
        System.out.println(pocetBinarneZaujimavychLong(4364481400268379269L)); // 1091120350067094817
        System.out.println(pocetBinarneZaujimavychLong(7184619486381948187L)); // 1796154871595487047
        System.out.println(4364481400268379269L%4);
        System.out.println(7184619486381948187L%4);
    }
}
