public class Konstanta extends Formula{
    boolean val;

    public Konstanta(boolean val) {
        this.val = val;
    }

    @Override
    public boolean hodnota(int vstup) {
        return val;
    }

    @Override
    public int vsetkyVstupy() {
        return 0;
    }

    @Override
    public String toString() {
        return Boolean.toString(val);
    }
}
