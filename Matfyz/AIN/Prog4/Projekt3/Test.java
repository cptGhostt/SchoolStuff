import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
String[] prikladovyVstup = new String[]{"12345", "789", "abcdef"};

Transformacia rns = new RiadkyNaStlpce();
Transformacia r90r = new Rotuj90(SMER.DOPRAVA);
Transformacia r90l = new Rotuj90(SMER.DOLAVA);
Transformacia or = new Obrat(TYP.RIADKY);
Transformacia os = new Obrat(TYP.STLPCE);
Transformacia kombo = new KombinaciaTransformacii(os, or);

System.out.println(Arrays.toString(rns.aplikuj(prikladovyVstup))); // ["17a", "28b", "39c", "4 d", "5 e", "  f"]
System.out.println(Arrays.toString(r90r.aplikuj(prikladovyVstup))); // [ "a71", "b82", "c93", "d 4", "e 5", "f"]
System.out.println(Arrays.toString(r90r.aplikuj(r90r.aplikuj(prikladovyVstup)))); // ["fedcba", "987", "54321"]
System.out.println(Arrays.toString(r90l.aplikuj(prikladovyVstup))); // ["59f", "48e", "37d", "2 c", "1 b", "  a"]
System.out.println(Arrays.toString(or.aplikuj(prikladovyVstup))); // ["54321", "987", "fedcba"]
System.out.println(Arrays.toString(os.aplikuj(prikladovyVstup))); // ["abcdef", "789", "12345"]
System.out.println(Arrays.toString(kombo.aplikuj(prikladovyVstup))); // ["fedcba", "987", "54321"]
    }
}
