public class Delenie extends Vyraz {
    private Vyraz lavaStrana;
    private Vyraz pravaStrana;

    public Delenie(){}

    public Delenie(Vyraz lavaStrana, Vyraz pravaStrana){
        this.lavaStrana = lavaStrana;
        this.pravaStrana = pravaStrana;
    }

    @Override
    public double vyries() {
        return lavaStrana.vyries() / pravaStrana.vyries();
    }

    @Override
    public String toString() {
        return '(' +
                lavaStrana.toString() +
                " / " +
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