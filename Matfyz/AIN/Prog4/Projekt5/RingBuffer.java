import java.util.ArrayList;
import java.util.Arrays;

public class RingBuffer<T>{
    protected T[] buffer;
    protected int capacity;
    protected int size;
    protected int index;


    @SuppressWarnings("unchecked")
    RingBuffer(int kapacita){
        buffer = (T[]) new Object[kapacita];
        capacity = kapacita;
        size = 0;
        index = 0;
    }

    @Override
    public String toString(){
        return Arrays.toString(this.buffer);
    }

    public int size(){
        return size;
    }

    public T top(){
        if (index == 0) return buffer[buffer.length - 1];
        return buffer[index-1];
    }

    public T get(int index){
        try {
            return buffer[index];
        } catch (ArrayIndexOutOfBoundsException e) {
            return null;
        }
    }

    @SuppressWarnings("unchecked")
    public T[] get(int index, int pocet){
        T[] temp = (T[]) new Object[pocet];
        int i = 0, j = index;

        for (; index < j+pocet; index++){
            temp[i] = buffer[index%capacity];
            i++;
        }

        return temp;
    }

    public boolean push(T hodnota){
        if (size == capacity) return false;

        while (buffer[index] != null){
            index++;
            index %= capacity;
        }
        buffer[index] = hodnota;
        index++;
        index %= capacity;
        size++;
        return true;
    }

    public int push(T[] hodnoty){
        int i = 0;

        while (i != hodnoty.length && size != capacity){
            if (buffer[index] == null){
                buffer[index] = hodnoty[i];
                size++;
                i++;
            }
            index++;
            index %= capacity;
        }

        return i;
    }

    @SuppressWarnings("unchecked")
    public T[] pushForce(T[] hodnoty){
        ArrayList<T> temp = new ArrayList<T>();

        for (T t : hodnoty){
            if (buffer[index] != null){
                temp.add(buffer[index]);
            } else {
                size++;
            }
            buffer[index] = t;
            index++;
            index %= capacity;
        }

        return (T[]) temp.toArray();
    }

    @SuppressWarnings("unchecked")
    public T[] remove(int index, int pocet){
        ArrayList<T> temp = new ArrayList<>();
        int i = index;

        for (; index < i+pocet; index++){
            if (buffer[index%capacity] == null) break;
            temp.add(buffer[index%capacity]);
            buffer[index%capacity] = null;
            size--;
        }

        return (T[]) temp.toArray();
    }

    public static void main(String[] args) {
        RingBuffer<Integer> r = new RingBuffer<Integer>(3);         //{null, null, null}; index=0
        r.push(20);                                                 //{20, null, null}; index=1
        r.push(30);                                                 //{20, 30, null}; index=2
        System.out.println(r.top());                                        //30
        r.push(40);                                                 //{20, 30, 40}; index=0
        System.out.println(r.size());                                       //3
        r.remove(0, 2);                                         //{null, null, 40}; index=0
        r.push(new Integer[]{5, 10, 15, 20, 25, 30, 35});                   //{5, 10, 40}; index=2
        r.remove(1,1);                                          //{5, null, 40}; index=2
        System.out.println(r.top());                                        //null
        System.out.println(Arrays.toString(r.get(2, 2)));       //{40, 5}
        r.pushForce(new Integer[]{100, 200});                               //{200, null, 100}; index=1
    }
}
