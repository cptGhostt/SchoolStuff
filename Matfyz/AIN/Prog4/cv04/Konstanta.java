public class Konstanta extends Vyraz {
    private double hodnota;

    public Konstanta(){}

    public Konstanta(double hodnota){
        this.hodnota = hodnota;
    }

    @Override
    public double vyries() { //TODO
        return hodnota;
    }

    @Override
    public String toString() { //TODO
        return Double.toString(hodnota);
    }

    @Override
    public void setLavaStrana(Vyraz lavaStrana) { //TODO, môžte nechať prázdne
    }

    @Override
    public void setPravaStrana(Vyraz pravaStrana) { //TODO, môžte nechať prázdne
    }

}
