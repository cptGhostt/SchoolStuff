abstract public class Formula {
    public abstract boolean hodnota(int vstup);   // vypočíta hodnotu formule
    public abstract int vsetkyVstupy();           // vráti indexy všetkých vstupov=premenných vo formuli
    public boolean tautologia() {
        int vstup = vsetkyVstupy();
        StringBuilder sb = new StringBuilder();
        sb.append(Integer.toBinaryString(vstup));
        sb = sb.reverse();
        vstup = 0;

        if (!hodnota(vstup)) return false;

        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) == '1') {
                vstup = vstup | 1 << i;
                if (!hodnota(vstup)) return false;
                for (int j = i + 1; j < sb.length(); j++) {
                    if (sb.charAt(j) == '1') {
                        vstup = vstup | 1 << j;
                        if (!hodnota(vstup)) return false;
                    }
                }
                vstup = 0;
            }
        }

        return true; }           // zistí, či je pravdivá pre ľubovoľné vstupy
}