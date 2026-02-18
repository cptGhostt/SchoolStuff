public class Premenna{
    private char nazov;
    private Vyraz vyraz;
    private double hodnota;

    public Premenna(char nazov, Vyraz vyraz){
        this.nazov = nazov;
        this.vyraz = vyraz;
        setHodnota();
    }

    public double getHodnota(){ //TODO
        return hodnota;
    }

    public Vyraz getVyraz(){ //TODO
        return vyraz;
    }

    public char getNazov(){ //TODO
        return nazov;
    }

    public void setHodnota(){
        hodnota = vyraz.vyries();
    }

    public String toString() { //TODO
        return nazov + " = " + hodnota;
    }
}

