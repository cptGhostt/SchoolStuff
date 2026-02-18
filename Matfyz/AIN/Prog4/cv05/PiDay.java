import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class PiDay {
    public static void find() {

        try {
            String pi = Files.readAllLines(Paths.get("pi.txt")).get(0);
            String max = "";

            for (int i = 0; i < pi.length(); i++) {
                int right = i+1;
                int left = i-1;
                String s;

                while(right < pi.length() && left >= 0) {
                    if (pi.charAt(left) == pi.charAt(right)) {
                        s = pi.substring(left, right+1);
                        if (s.length() > max.length()) {
                            max = s;
                        }
                        left--;
                        right++;
                    } else break;
                }
            }

            System.out.println(max);

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static String najdlhsi() {return "9475082805749";}

    public static void main(String[] args) {
        find();
    }

}
