public class Not extends Formula{
    Formula formula;

    public Not(Formula vstup) {
        formula = vstup;
    }

    @Override
    public boolean hodnota(int vstup) {
        return !formula.hodnota(vstup);
    }

    @Override
    public int vsetkyVstupy() {
        return formula.vsetkyVstupy();
    }

    @Override
    public String toString() {
        return "not(" + formula.toString() + ")";
    }
}
