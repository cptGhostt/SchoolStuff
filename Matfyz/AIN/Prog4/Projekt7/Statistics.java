import java.util.*;

public class Statistics {

    public static String topPriezviskoOffice(Office kancel){  //vráti ľubovoľné najčastejšie vyskutujúce sa priezvisko v office
        HashMap<String, Integer> names = new HashMap<>();
        names.put(kancel.getVeduci().getPriezvisko(), 1);

        for (Employee employee : kancel.getPodriadeni()){
            if (names.containsKey(employee.getPriezvisko())){
                names.put(employee.getPriezvisko(), names.get(employee.getPriezvisko()) + 1);
            } else {
                names.put(employee.getPriezvisko(), 1);
            }
        }

        String bestString = "";
        int bestInt = 0;
        for (String name : names.keySet()){
            if (names.get(name) > bestInt){
                bestInt = names.get(name);
                bestString = name;
            }
        }
        return bestString;
    }

    public static String topPriezviskoFirma(List<Office> kancelarie){  //vráti ľubovoľné najčastejšie vyskutujuce sa priezvisko vo firme
        HashMap<String, Integer> names = new HashMap<>();

        for (Office kancel : kancelarie){

            if (names.containsKey(kancel.getVeduci().getPriezvisko())){
                names.put(kancel.getVeduci().getPriezvisko(), names.get(kancel.getVeduci().getPriezvisko()) + 1);
            }
            else {
                names.put(kancel.getVeduci().getPriezvisko(), 1);
            }

            for (Employee employee : kancel.getPodriadeni()){
                if (names.containsKey(employee.getPriezvisko())){
                    names.put(employee.getPriezvisko(), names.get(employee.getPriezvisko()) + 1);
                }
                else {
                    names.put(employee.getPriezvisko(), 1);
                }
            }
        }

        String bestString = "";
        int bestInt = 0;
        for (String name : names.keySet()){
            if (names.get(name) > bestInt){
                bestInt = names.get(name);
                bestString = name;
            }
        }
        return bestString;
    }

    public static Project najviacHotovejRoboty(List<Project> projekty){ //vráti ľubovoľný projekt, na ktorom sa priemerne spravilo najviac hodín a je hotový
        Project bestProjet = null;
        double bestValue = 0.0;
        for (Project projekt : projekty){
            if (projekt.isHotovy()){
                double value = (double) projekt.getStravenyCasSpolu() / (double) projekt.getRiesitelia().size();
                if (value > bestValue){
                    bestProjet = projekt;
                    bestValue = value;
                }
            }
        }
        return bestProjet;
    }

    public static Employee topPracant(List<Project> projekty){ //vráti ľubovoľného zamestnanca s najväčším počtom hodín (aj na nehotových projektoch)
        HashMap<Office, Double> counts = new HashMap<>();

        for (Project projekt : projekty){
            for (Office office : projekt.getRiesitelia()){
                if (counts.containsKey(office)){
                    counts.put(office, counts.get(office) + (double) projekt.getStravenyCasSpolu() / (double) projekt.getRiesitelia().size());
                }
                else {
                    counts.put(office, (double) projekt.getStravenyCasSpolu() / (double) projekt.getRiesitelia().size());
                }
            }
        }

        Office bestOffice = null;
        double bestInt = 0;
        for (Office office : counts.keySet()){
            if (counts.get(office) > bestInt){
                bestInt = counts.get(office);
                bestOffice = office;
            }
        }
        return bestOffice.getVeduci();
    }

    public static void main(String[] args) {
        Employee janoMrkva = new Employee(1, "Jano", "Mrkva");
        Employee dezoBaklazan = new Employee(2, "Dezo", "Baklazan");
        Employee danoMrkva = new Employee(3, "Dano", "Mrkva");
        Employee feroKukurica = new Employee(4, "Fero", "Kukurica");

        ArrayList<Employee> em1 = new ArrayList<>(Arrays.asList(dezoBaklazan, danoMrkva));
        ArrayList<Employee> em2 = new ArrayList<>(new ArrayList<>());

        Office of1 = new Office(1, janoMrkva, em1);
        Office of2 = new Office(2, feroKukurica, em2);

        ArrayList<Office> op1 = new ArrayList<>(Arrays.asList(of1));
        ArrayList<Office> op2 = new ArrayList<>(Arrays.asList(of2));
        ArrayList<Office> op12 = new ArrayList<>(Arrays.asList(of1, of2));

        Project projekt1 = new Project(1, op1, 1000, true);
        Project projekt2 = new Project(2, op1, 20, false);
        Project projekt3 = new Project(3, op2, 350, true);
        Project projekt4 = new Project(4, op12, 1300, true);
        Project projekt5 = new Project(5, op12, 1350, false);

        System.out.println(topPriezviskoOffice(of1));  //Mrkva
        System.out.println(topPriezviskoOffice(of2));  //Kukurica

        System.out.println(topPriezviskoFirma(op12));  //Mrkva

        System.out.println(najviacHotovejRoboty(List.of(projekt4, projekt5)));  //projekt4
        System.out.println(najviacHotovejRoboty(List.of(projekt1, projekt4)));  //projekt1

        System.out.println(topPracant(List.of(projekt4, projekt5)));  //napr. Jano Mrkva
        System.out.println(topPracant(List.of(projekt1, projekt4)));  //napr. Jano Mrkva
        System.out.println(topPracant(List.of(projekt1, projekt2, projekt3, projekt4, projekt5)));  //Fero Kukurica
    }
}
