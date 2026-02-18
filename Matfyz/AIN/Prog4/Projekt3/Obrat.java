import java.util.ArrayList;

enum TYP { RIADKY, STLPCE }
record Obrat(TYP typ) implements Transformacia{
    public String[] aplikuj(String[] s) {
        ArrayList<String> list = new ArrayList<>();
        if (typ == TYP.STLPCE) {
            for (int i = s.length - 1; i >= 0; i--) {
                list.add(s[i]);
            }
        } else {
            for (int i = 0; i < s.length; i++) {
                StringBuilder sb = new StringBuilder(s[i]);
                list.add(sb.reverse().toString());
            }
        }


        return list.toArray(new String[list.size()]);
    }
}
