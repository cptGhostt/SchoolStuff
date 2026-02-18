public class Premenna extends Polynom {
    String var;

    public Premenna(String s) {
        var = s;
    }

    @Override
    Double valueAt(String[] vars, double[] values) {
        for (int i = 0; i < vars.length; i++) {
            if (vars[i].equals(var)) return values[i];
        }
        return 0.0;
    };
    @Override
    Polynom derive(String var) {
        return new Konstanta(this.var.equals(var) ? 1 : 0); }

    @Override
    public String toString() {
        return var;
    }
}
