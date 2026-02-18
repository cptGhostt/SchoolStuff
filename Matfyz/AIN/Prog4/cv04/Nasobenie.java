public class Nasobenie extends Vyraz {
    private Vyraz lavaStrana;
    private Vyraz pravaStrana;

    public Nasobenie(){}

    public Nasobenie(Vyraz lavaStrana, Vyraz pravaStrana){
        this.lavaStrana = lavaStrana;
        this.pravaStrana = pravaStrana;
    }

    @Override
    public double vyries() { //TODO
        return lavaStrana.vyries() * pravaStrana.vyries();
    }

    @Override
    public String toString() {
        return '(' +
                lavaStrana.toString() +
                " * " +
                pravaStrana.toString() +
                ')';
    }

    @Override
    public void setLavaStrana(Vyraz lavaStrana) {
        this.lavaStrana = lavaStrana;
    }

    @Override
    public void setPravaStrana(Vyraz pravaStrana) {
        this.pravaStrana = pravaStrana;
    }
}