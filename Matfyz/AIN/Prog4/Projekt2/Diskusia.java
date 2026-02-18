import java.util.ArrayList;

public class Diskusia {

    public static int hadky(int n, long b) {
        String s = (Long.toBinaryString(b));
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n - s.length(); i++) {
            sb.append("0");
        }
        sb.append(s);
        StringBuilder row1 = new StringBuilder();
        row1.append(sb.charAt(0));
        StringBuilder row2 = new StringBuilder();

        for (int i = 1; i < n; i++) {
            if (sb.charAt(i) == row1.charAt(row1.length() - 1)) {
                row2.append(sb.charAt(i));
            } else {
                row1.append(sb.charAt(i));
            }
        }


        return arguments(row1.toString()) + arguments(row2.toString());
    }



    public static int arguments(String row){
        int total = 0;
        for (int i = 1; i < row.length(); i++) {
            if (row.charAt(i) != row.charAt(i-1)) {
                total++;
            }
        }
        return total;
    }

    public static void main(String[] args) {
        System.out.println(hadky(4, 0b1100)); // 2
        System.out.println(hadky(12, 0b001101100100)); // 8
        System.out.println(hadky(3, 0b011)); // 1
        System.out.println(hadky(6, 0b001010 )); // 4
    }
}
