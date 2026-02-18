/**
 * PrioritnyFront - cvicenie 5
 */

import java.util.PriorityQueue;

/**
 * Java contains a class PrioirtyQueue, we can utilize it for our purpose,
 * and simply implement a wrapper.
 */
public class PrioritnyFront<E> implements FrontInterface<E>{
    PriorityQueue<Elem<E>> pq;

    public PrioritnyFront() {
        pq = new PriorityQueue<>();
    }

    /**
     * add new element to priority queue
     */
    public void enqueue(E elem, int prio) {
        pq.offer(new Elem<>(prio, elem));
    }

    /**
     * remove (and return) the element with the lowest priority from queue
     */
    public E dequeue() {
        if (pq.isEmpty()) return null;

        return pq.poll().getElement();
    }

    @Override
    public boolean isEmpty() {
        return pq.isEmpty();
    }

    /**
     * return the element with the highest priority from queue, but do not remove it
     */
    public E front() {
        if (pq.isEmpty()) return null;
        return pq.peek().getElement();
    }

    /**
     * return the number of elements that remain in the queue
     */
    public int size() {
        return pq.size();
    }

    /**
     * Test program - inserts random elements to priority queue and retrieves them
     *
     * @param args - program takes no arguments
     */
    public static void main(String[] args) {
        // girls
        PrioritnyFront<String> f = new PrioritnyFront<>();
        f.enqueue(new String("janka"), 5);
        f.enqueue(new String("danka"), 2);
        f.enqueue(new String("hanka"), 1);
        f.enqueue(new String("anka"), 4);
        f.enqueue(new String("zuzanka"), 3);
        f.enqueue(new String("elenka"), 1);
        f.enqueue(new String("zofka"), 6);
        f.enqueue(new String("evka"), 4);
        System.out.println(f);
        while (f.size() > 0) {
            System.out.println(f.dequeue());
        }

        // random numbers
        PrioritnyFront<Integer> f2 = new PrioritnyFront<Integer>();
        // generate 10 random numbers 0-49 and insert them on the queue
        // with the same priority as their value
        for (int i = 0; i < 10; i++) {
            int x = (int) (50 * Math.random());
            f2.enqueue(x, x);
        }
        // now remove the numbers from the queue in the priority order and print them
        for (int i = 0; i < 10; i++)
            System.out.print(f2.dequeue() + ",");
        if (f2.size() == 0) System.out.println("empty");
    }
}
