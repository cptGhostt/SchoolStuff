public class EasyRegex {
    public static boolean jeDobry(String regex, String retazec){
        boolean brackets = false;
        int i = 0, j = 0;
        StringBuilder sb = new StringBuilder();

        while(i < regex.length()){
            if (!brackets){
                if (regex.charAt(i) == '['){
                    brackets = true;
                    sb.append(regex.charAt(i));

                } else {
                    if (regex.charAt(i) != retazec.charAt(j)) return false;
                    j++;
                }
            } else {
                if (regex.charAt(i) == ']'){
                    brackets = false;
                    sb.append(regex.charAt(i));
                    if (!zatvorky(sb.toString(), retazec.charAt(j))) return false;
                    j++;
                    sb = new StringBuilder();

                } else {
                    sb.append(regex.charAt(i));
                }
            }
            i++;
        }

        return true;
    }

    public static boolean vRozsahuCisel(char hodnota, int zac, int kon){
        return (hodnota - '0' >= zac && hodnota - '0' <= kon);
    }

    public static boolean vRozsahuPismen(char hodnota, char zac, char kon){
        return (hodnota >= zac && hodnota <= kon);
    }

    public static boolean zatvorky(String regex, char hodnota){
        if (regex.length() == 5 && regex.charAt(2) == '-'){
            if (Character.isDigit(regex.charAt(1))){
                return vRozsahuCisel(hodnota, regex.charAt(1) - '0', regex.charAt(3) - '0');
            }
            return vRozsahuPismen(hodnota, regex.charAt(1), regex.charAt(3));
        }
        return regex.indexOf(hodnota) != -1;
    }

    public static void main(String[] args) {
        System.out.println(jeDobry("098[357][1-4][a-x]b[c-y]DD[0-1][Y-Z]", "09854abcDD0Z"));
        System.out.println(jeDobry("098[357][1-4][a-x]b[c-y]DD[0-1][Y-Z]", "09854abaDD0Z"));
        System.out.println(vRozsahuCisel('5', 1, 7));
        System.out.println(vRozsahuCisel('5', 1, 4));
        System.out.println(vRozsahuPismen('A', 'A', 'X') );
        System.out.println(zatvorky("[1-4]", '4'));
        System.out.println(zatvorky("[1-4]", 'a'));
    }
}
