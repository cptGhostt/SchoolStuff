public class Elem<E> implements Comparable<Elem<E>> {
    private int prior;
    private E element;

    public Elem(int prior, E element) {
        this.prior = prior;
        this.element = element;
    }

    public int getPrior() {
        return prior;
    }

    public E getElement() {
        return element;
    }

    @Override
    public int compareTo(Elem<E> o) {
        return prior - o.prior;
    }
}