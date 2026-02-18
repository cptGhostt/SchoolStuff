import java.util.ArrayList;
import java.util.List;

public class KSucin {

	public static <E> List<List<E>> sucin(List<List<E>> lists) {
		List<List<E>> toReturn = new ArrayList<>();
		int finalSize = 1;
		for (List<E> list : lists) {
			finalSize *= list.size();
		}

		int[] indexes = new int[lists.size()];

		while (toReturn.size() < finalSize) {
			List<E> newList = new ArrayList<>();
			for (int i = 0; i < indexes.length; i++) {
				newList.add(lists.get(i).get(indexes[i]));
			}
			toReturn.add(newList);

			boolean overflow = true;
			for (int i = indexes.length - 1; i >= 0; i--) {
				if (overflow) {
					overflow = false;
					indexes[i]++;

					if (indexes[i] >= lists.get(i).size()) {
						indexes[i] = 0;
						overflow = true;
					}
				}
			}
		}

		return toReturn;  // dodefinuj
	}	
	public static void main(String[] args) {
		{
			List<Integer> al1 = new ArrayList<>(); al1.add(1); al1.add(2); al1.add(3);
			List<Integer> al2 = new ArrayList<>(); al2.add(4); al2.add(5); al2.add(6);
			List<Integer> al3 = new ArrayList<>(); al3.add(10); al3.add(11);
			
			List<List<Integer>> ll = new ArrayList<>();
			ll.add(al1); ll.add(al2); ll.add(al3);
			
			System.out.print("sucin(" + ll + ")=");
			List<List<Integer>> res = sucin(ll);
			System.out.println(res + ", " + res.size());
		}
	}
}
