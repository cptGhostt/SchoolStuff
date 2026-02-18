import java.util.HashSet;
import java.util.Set;

public class Infinite {
    public static <E> boolean infinite(Node<E> first) {
        Node<E> turtle = first;
        Node<E> rabbit = first;

        while (rabbit != null) {
            turtle = turtle.getNext();
            rabbit = rabbit.getNext().getNext();
            if (turtle == rabbit) {
                return true;
            }
        }

        return false;
    }
}
