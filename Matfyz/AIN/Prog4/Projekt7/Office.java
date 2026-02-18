import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Office {
    private int id;
    private Employee veduci;  //v office su veduci a podriadeni, podriadeni podriadeneho neexistuje
    private ArrayList<Employee> podriadeni;

    public Office(int id, Employee veduci, ArrayList<Employee> podriadeni) {
        this.id = id;
        this.veduci = veduci;
        this.podriadeni = podriadeni;
    }

    public int getId() {
        return id;
    }

    public Employee getVeduci() {
        return veduci;
    }

    public int getSize(){
        return podriadeni.size() + 1;
    }

    public List<Employee> getAll(){
        List<Employee> all = new ArrayList<>(getPodriadeni());
        all.add(veduci);
        return all;
    }

    public List<Employee> getPodriadeni() {
        return podriadeni;
    }

    @Override
    public String toString() {
        return "Office{" +
                "id=" + id +
                ", veduci=" + veduci +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Office office = (Office) o;
        return id == office.id;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }
}
