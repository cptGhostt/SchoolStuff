public class CezarovaSifra extends Sifra {
    @Override
    public String zasifruj(String sprava) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < sprava.length(); i++) {
            if ((int) sprava.charAt(i) == 255) sb.append((char) 2);
            else if ((int) sprava.charAt(i) == 254) sb.append((char) 1);
            else if ((int) sprava.charAt(i) == 253) sb.append((char) 0);
            else sb.append((char)(sprava.charAt(i) + 3));
        }

        return sb.toString();
    }

    @Override
    public String desifruj(String sprava) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < sprava.length(); i++) {
            if ((int) sprava.charAt(i) == 2) sb.append((char) 255);
            else if ((int) sprava.charAt(i) == 1) sb.append((char) 254);
            else if ((int) sprava.charAt(i) == 0) sb.append((char) 253);
            else sb.append((char)(sprava.charAt(i) - 3));
        }

        return sb.toString();
    }
}
