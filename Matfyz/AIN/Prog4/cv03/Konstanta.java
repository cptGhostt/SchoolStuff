public class Konstanta extends Polynom {
    double val;
    public Konstanta(double k) {
        val = k;
    }
    @Override
    Double valueAt(String[] vars, double[] values) { return val; };
    @Override
    Polynom derive(String var) { return new Konstanta(0); };

    @Override
    public String toString() { return String.valueOf(val); };
}
