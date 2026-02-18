public class Gramatika {

    public static String change(String s){
        String toRet = "";
        String buff = "";

        for (int i=0; i<s.length(); i++) {
            buff += s.charAt(i);

            if (i != 0) {
                if (buff.equals("AA")) toRet += "B";
                else if (buff.equals("AB")) toRet += "A";
                else if (buff.equals("AC")) toRet += "A";
                else if (buff.equals("BA")) toRet += "C";
                else if (buff.equals("BB")) toRet += "A";
                else if (buff.equals("BC")) toRet += "C";
                else if (buff.equals("CA")) toRet += "AA";
                else if (buff.equals("CB")) toRet += "A";
                else if (buff.equals("CC")) toRet += "BB";
                buff = buff.charAt(1) + "";
            }
        }

        return toRet;
    }

    public static int numberOfIter(String s){
        int toRet = 0;
        while (s.length() > 1) {
            s = change(s);
            toRet++;
        }
        return toRet;
    }

    public static boolean isCorrectOutput(String s, char c){
        while (s.length() > 1) {
            s = change(s);
        }
        return s.charAt(0) == c;
    }

    public static void main(String[] args) {
        System.out.println(change("ABC"));
        System.out.println(change("BCCBC"));
        System.out.println(numberOfIter("ABC"));
        System.out.println(numberOfIter("BCCBC"));
        System.out.println(isCorrectOutput("ABC", 'C'));
        System.out.println(isCorrectOutput("BCCBC", 'B'));

    }
}
