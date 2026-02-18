import java.util.Arrays;
import java.util.HashSet;

public class Union extends AbstractStringSet{
	AbstractStringSet set1;
	AbstractStringSet set2;

	// Konstruktor, zapamata si ake mnoziny zjednocujeme
	public Union(AbstractStringSet a, AbstractStringSet b) {
		set1 = a;
		set2 = b;
	}

	public boolean contains(String s) { return (set1.contains(s)) || (set2.contains(s)); }

	public  String[] getElements(){
		HashSet<String> set = new HashSet<>(Arrays.asList(set1.getElements()));
		set.addAll(Arrays.asList(set2.getElements()));

		return set.toArray(new String[set.size()]);
	}
}
