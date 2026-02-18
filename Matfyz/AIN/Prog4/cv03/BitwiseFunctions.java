public class BitwiseFunctions {  //bez použitia cyklov; použitím binárnych operácií;

    public static int vynulujJednotkovyBit(int cislo){ //najpravejsi jednotkovy bit zmen na 0
        return cislo & (cislo - 1);
    }

    public static boolean jeMocninaDvojky(int cislo){  //zisti ci je cislo mocnina dvojky
        return cislo > 0 && (cislo & (cislo - 1)) == 0;
    }

    public static boolean najviacDveJednotkove(int cislo){ //zisti, či čislo v binarnej reprezentacii nema nikdy viac ako 2 jednotky po sebe
        return (cislo & (cislo << 1) & (cislo << 2)) == 0;
    }

    public static int dalsieSRovnakymPoctom(int cislo){  //najdi prve vacsie cislo ktore ma rovnaky pocet jednotiek
        if (cislo == 0) return 0;

        int smallest = cislo + (cislo & -cislo);
        int ones = cislo ^ smallest;
        ones = (ones >> 2) / (cislo & -cislo);
        return smallest | ones;
    }

    public static void main(String[] args) {
        for (int i = 0; i <= 10; i++){
            if (jeMocninaDvojky(i)) System.out.println("Mocnina dvojky je aj: " +i);
            if(najviacDveJednotkove(i)) System.out.println("Najviac dve jednotky po sebe ma aj: " + i);
            System.out.println("Vynulovana najpravejsia jednotka cisla " + i + " vytvara cislo: " + vynulujJednotkovyBit(i));
            System.out.println("Dalsie cislo s rovnakym poctom jednotiek ako " + i + " je cislo: " + dalsieSRovnakymPoctom(i));
        }
    }
}
