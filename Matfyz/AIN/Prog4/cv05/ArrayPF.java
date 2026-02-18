/**
 * implementacia prioritneho frontu pomocu pola
 *
 * @param <E> idea, ktoru realizujte: konstruktor naalokuje pole velkosti size.
 *            Nejde to urobit takto E[] pole = new E[size], dovody su v prednaske
 *            Ide to urobit takto E[] pole = (E[])new Object[size]
 *            dequeue musi vratit prvok s najmensou prioritou, preto je najrozumnejsie, aby bole prvkov typu E bolo
 *            utriedene podla priorit, od najmensej po najvacsiu. Kedze prvky pribudaju a ubudaju, zistite z prednasky
 *            ako sa implementuje front v poli efektivne, aby ste ho stale neposuvali v poli. Stacia na to dva indexy, prvy
 *            a posledny, a rozmyslat, ze front moze odkracat cez hranu pola. Modulo size vas zahrani.
 *            Ak mate ploe utriedene, tak dequeue je trivialne, vyberie prvy prvok frontu.
 */
public class ArrayPF<E> implements FrontInterface<E> {


    Dvojica<E>[] array;
    int size;
    int count = 0;
    int start = 0, end = 0;

    /**
     * konstruktor
     */
    @SuppressWarnings("unchecked")
    public ArrayPF(int size) {
        array = (Dvojica<E>[]) new Dvojica<?>[size];
        this.size = size;
    }

    /**
     * zarad prvok elem s prioritou prio
     */
    @Override
    public void enqueue(E elem, int prio) {
        if (count == size) return;

        if (count == 0){
            array[start] = new Dvojica<E>(elem, prio);
            start++;
            count++;
            return;
        }

        int i;
        for (i = start -1; (i >= end) && array[i%size].prio > prio; i--){
            array[i%size + 1] = array[i%size];
        }

        array[i%size + 1] = new Dvojica<E>(elem, prio);
        count++;
        start++;

    }

    /**
     * vyber prvok s najmensou prioritou
     */
    @Override
    public E dequeue() {
        if (count == 0) return null;
        Dvojica<E> tmp = array[end];
        end++;
        count--;
        return tmp.elem;
    }

    /**
     * test, ci je front prazdny
     */
    @Override
    public boolean isEmpty() {
        return count == 0;
    }

    public static void main(String[] args) {
		FrontInterface<String> f = new ArrayPF<>(100);
        f.enqueue(new String("janka"), 5);
        f.enqueue(new String("danka"), 2);
        f.enqueue(new String("hanka"), 1);
        f.enqueue(new String("anka"), 4);
        f.enqueue(new String("zuzanka"), 3);
        f.enqueue(new String("elenka"), 1);
        f.enqueue(new String("zofka"), 6);
        f.enqueue(new String("evka"), 4);
        System.out.println(f);
        while (!f.isEmpty()) {
            System.out.println(f.dequeue());
        }
    }

}

class Dvojica<E>{
    E elem;
    int prio;
    public Dvojica(E elem, int prio) {
        this.elem = elem;
        this.prio = prio;
    }
}
