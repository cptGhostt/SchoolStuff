public class Or extends Formula{
    Formula left;
    Formula right;

    public Or(Formula left, Formula right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public boolean hodnota(int vstup) {
        return left.hodnota(vstup) || right.hodnota(vstup);
    }

    @Override
    public int vsetkyVstupy() {
        return left.vsetkyVstupy() | right.vsetkyVstupy();
    }

    @Override
    public String toString() {
        return '(' + left.toString() + " || " + right.toString() + ')';
    }

}
