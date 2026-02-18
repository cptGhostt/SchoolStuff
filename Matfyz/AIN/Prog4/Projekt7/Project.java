import java.util.ArrayList;
import java.util.Objects;

public class Project {
    private int id;
    private ArrayList<Office> riesitelia;  //na projekte sa vždy podieľajú všetci ľudia z officov rovnomerným časovým zaťažením
    private long stravenyCasSpolu;
    private boolean hotovy;

    public Project(int id, ArrayList<Office> riesitelia, long stravenyCasSpolu, boolean hotovy){
        this.id = id;
        this.riesitelia = riesitelia;
        this.stravenyCasSpolu = stravenyCasSpolu;
        this.hotovy = hotovy;
    }

    public int getId() {
        return id;
    }

    public ArrayList<Office> getRiesitelia() {
        return riesitelia;
    }

    public long getStravenyCasSpolu() {
        return stravenyCasSpolu;
    }

    public boolean isHotovy() {
        return hotovy;
    }

    @Override
    public String toString() {
        return "Project{" +
                "id=" + id +
                ", riesitelia=" + riesitelia +
                ", stravenyCasSpolu=" + stravenyCasSpolu +
                ", hotovy=" + hotovy +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Project project = (Project) o;
        return id == project.id;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }
}
