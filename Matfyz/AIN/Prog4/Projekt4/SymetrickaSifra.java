public class SymetrickaSifra extends Sifra {
    String key;

    public SymetrickaSifra(String key) {
        this.key = key;
    }

    @Override
    public String zasifruj(String sprava) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < sprava.length(); i++) {
            sb.append((char)(sprava.charAt(i) + (int)(key.charAt(i%key.length()) - 'a' + 1)%256));
        }

        return sb.toString();
    }

    @Override
    public String desifruj(String sprava) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < sprava.length(); i++) {
            sb.append((char)(sprava.charAt(i) - (int)(key.charAt(i%key.length()) - 'a' + 1)%256));
        }

        return sb.toString();
    }
}
