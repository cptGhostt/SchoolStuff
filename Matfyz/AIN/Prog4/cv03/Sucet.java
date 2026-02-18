public class Sucet extends Polynom {
    Polynom p1, p2;

    public Sucet(Polynom a, Polynom b) {
        p1 = a;
        p2 = b;
    }

    @Override
    Double valueAt(String[] vars, double[] values) {
        return p1.valueAt(vars, values) + p2.valueAt(vars, values);
    }

    @Override
    Polynom derive(String var) {
        return new Sucet(p1.derive(var), p2.derive(var));
    }

    @Override
    public String toString() {
        return "(" + p1 + " + " + p2 + ")";
    }
}
