import java.util.ArrayList;

class RiadkyNaStlpce implements Transformacia {

    public String[] aplikuj(String[] s){
        ArrayList<String> list = new ArrayList<>();
        int i = 0;
        for (int j = 0; j < s.length; j++) {
            if (s[j].length() > i) {
                i = s[j].length();
            }
        }

        int control = 0;
        for(;;){
            StringBuilder sb = new StringBuilder();

            for(int j = 0; j < s.length; j++){
                if (control < s[j].length()){
                    sb.append(s[j].charAt(control));
                } else {
                    sb.append(' ');
                }
            }
            list.add(sb.toString());
            control++;

            if (control == i) break;
        }

        return list.toArray(new String[list.size()]);
    }
}
