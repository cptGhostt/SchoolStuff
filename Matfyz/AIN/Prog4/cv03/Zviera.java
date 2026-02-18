abstract class Zviera {
    public abstract String urobZvuk();
}


class Zoo{
    public static void main(String[] args) {
        Zviera[] zoo = {new Pes(), new Macka()};

        for (Zviera z : zoo) {
            System.out.println(z.urobZvuk());
        }
    }
}
