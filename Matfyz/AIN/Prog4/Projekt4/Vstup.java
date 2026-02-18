public class Vstup extends Formula {
    int bit;

    public Vstup(int vstup) {
        bit = vstup;
    }

    @Override
    public boolean hodnota(int vstup) {
        StringBuilder sb = new StringBuilder();
        sb.append(Integer.toBinaryString(vstup));
        try {
            return sb.reverse().toString().charAt(bit) == '1';
        } catch (Exception e) {
            return false;
        }
    }

    @Override
    public int vsetkyVstupy() {
        return 1 << bit;
    }

    @Override
    public String toString() {
        return "bit_" + bit;
    }

}
