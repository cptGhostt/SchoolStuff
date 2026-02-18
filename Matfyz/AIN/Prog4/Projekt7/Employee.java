import java.util.Objects;

public class Employee {
    private Integer id;
    private String meno;
    private String priezvisko;

    public Employee(Integer id, String meno, String priezvisko){
        this.id = id;
        this.meno = meno;
        this.priezvisko = priezvisko;
    }

    public int getId() {
        return id;
    }

    public String getMeno() {
        return meno;
    }

    public String getPriezvisko() {
        return priezvisko;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "id=" + id +
                ", meno='" + meno + '\'' +
                ", priezvisko='" + priezvisko + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Employee employee = (Employee) o;
        return id == employee.id;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }
}
