import java.util.ArrayList;

enum SMER {
    DOLAVA,
    DOPRAVA
}
record Rotuj90(SMER smer) implements Transformacia {
    public String[] aplikuj(String[] s) {

        ArrayList<String> list = new ArrayList<>();
        int i = 0;
        for (int j = 0; j < s.length; j++) {
            if (s[j].length() > i) {
                i = s[j].length();
            }
        }

        if (smer == SMER.DOPRAVA) {
            int control = 0;
            for(;;){
                StringBuilder sb = new StringBuilder();

                for(int j = s.length-1; j >= 0; j--){
                    if (control < s[j].length()){
                        sb.append(s[j].charAt(control));
                    } else {
                        sb.append(' ');
                    }
                }
                list.add(sb.toString().strip());
                control++;

                if (control == i) break;
            }
        } else {
            int control = 0;
            for(;;){
                StringBuilder sb = new StringBuilder();

                for(int j = 0; j < s.length; j++){
                    if (s[j].length()-1-control >= 0) {
                        sb.append(s[j].charAt(s[j].length()-1-control));
                    } else {
                        sb.append(' ');
                    }
                }
                list.add(sb.toString());
                control++;

                if (control == i) break;
            }

        }

        return list.toArray(new String[list.size()]);
    }
}
