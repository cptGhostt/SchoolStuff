import java.util.Arrays;
import java.util.HashSet;

public class Intersection extends AbstractStringSet{
	AbstractStringSet set1;
	AbstractStringSet set2;
	
	// Konstruktor, zapamata si ake mnoziny tvoria prienik
	public Intersection(AbstractStringSet a, AbstractStringSet b) {
		set1 = a;
		set2 = b;
	}

	public boolean contains(String s) { return (set1.contains(s)) && (set2.contains(s)); }

	public  String[] getElements(){
		HashSet<String> a = new HashSet<>(Arrays.asList(set1.getElements()));
		HashSet<String> b = new HashSet<>(Arrays.asList(set2.getElements()));
		HashSet<String> set = new HashSet<>();

		for(String s : a){
			if (a.contains(s) && b.contains(s)) set.add(s);
		}

		return set.toArray(new String[set.size()]);
	}

}
