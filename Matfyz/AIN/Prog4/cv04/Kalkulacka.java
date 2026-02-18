public class Kalkulacka {
    public double dajHodnotuPremennej(Premenna[] premenne, char vyslednaPremenna){
        for(Premenna p : premenne){
            if (p.getNazov() == vyslednaPremenna){
                return p.getHodnota();
            }
        }

        return 0.0;
    }

    public double operujPremenne(Premenna[] premenne, Vyraz operacia){
        if(premenne.length == 1){
            return premenne[0].getHodnota();
        }

        operacia.setLavaStrana(new Konstanta(premenne[0].getHodnota()));
        for (int i = 1; i < premenne.length; i++){
            operacia.setPravaStrana(new Konstanta(premenne[i].getHodnota()));
            operacia.setLavaStrana(new Konstanta(operacia.vyries()));
        }
        operacia.setPravaStrana(new Konstanta(0));

        return operacia.vyries();
    }

    public static void main(String[] args) {
        Vyraz r = new Nasobenie(new Scitanie(new Konstanta(7), new Odcitanie(new Konstanta(8), new Konstanta(4))),
                new Delenie(new Nasobenie(new Konstanta(4), new Konstanta(3)), new Konstanta(5)));
        System.out.println(r.toString());  // ((7.0 + (8.0 - 4.0)) * ((4.0 * 3.0) / 5.0))
        System.out.println(r.vyries()); // 26.4
        Kalkulacka k = new Kalkulacka();
        Premenna[] p = new Premenna[]{new Premenna('x', r), new Premenna('y', new Konstanta(2)), new Premenna('z', new Konstanta(5))};
        System.out.println(k.dajHodnotuPremennej(p, 'x')); // 26.4
        System.out.println(k.operujPremenne(p, new Scitanie())); // 33.4
    }
}
