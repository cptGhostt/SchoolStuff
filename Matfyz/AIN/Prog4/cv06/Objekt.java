import java.util.Objects;

public class Objekt {
    String id;

    public Objekt(String id) {
        this.id = id;
    }

    @Override
    public String toString() {
        return id;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Objekt objekt = (Objekt) o;
        return Objects.equals(id, objekt.id);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(id);
    }
}
