public class Zaznam {
    private final String id;
    private final String mesto;
    private final double hodnota;

    public Zaznam(String meno, String mesto, double hodnota) {
        this.id = meno;
        this.mesto = mesto;
        this.hodnota = hodnota;
    }

    @Override
    public String toString() {
        return "Zaznam{" +
                "id senzora='" + id + '\'' +
                ", mesto='" + mesto + '\'' +
                ", hodnota=" + hodnota +
                '}';
    }

    public String getId() {
        return id;
    }

    public String getMesto() {
        return mesto;
    }

    public double getHodnota() {
        return hodnota;
    }
}