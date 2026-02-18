import java.util.HashSet;

public class StringSet extends AbstractStringSet{
	HashSet<String> set = new HashSet<>();
	int size = 0;
	// Konstruktor vytvori prazdnu mnozinu s danou kapacitou.
	public StringSet(int capacity) {
		size = capacity;
	}

	// Prida prvok do mnoziny. Vrati true ak sa prvok naozaj pridal,
	// vrati false ak nie (lebo taky prvok v mnozine uz bol, alebo je mnozina naplnena - pocet prvkov == kapacita).
    // Pridat mozeme aj null.
	public boolean add(String x) {
		if (set.size() >= size) return false;
		if (set.contains(x)) return false;
		set.add(x);
		return true;
	}

	public boolean contains(String s) {return set.contains(s);}

	public  String[] getElements(){return set.toArray(new String[set.size()]);}
}
