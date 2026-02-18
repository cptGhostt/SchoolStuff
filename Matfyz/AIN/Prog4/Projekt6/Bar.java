import java.util.List;
import java.util.Set;

public class Bar<E extends Comparable<E>> extends Mobile<E> {
	private int leftArm, rightArm;
	private Mobile<E> left, right;

	public Bar(int leftArm, int rightArm, Mobile<E> left, Mobile<E> right) {
		this.leftArm = leftArm;
		this.rightArm = rightArm;
		this.left = left;
		this.right = right;
	}
	@Override
	public String toString() {
		return "[" + left + ":" + leftArm  + "-" + rightArm  + ":" + right  + "]";
	}

	@Override
	int weight() {
		return 0;
	}

	@Override
	double width() {
		return 0;
	}

	@Override
	int height() {
		return 0;
	}

	@Override
	boolean balanced() {
		return false;
	}

	@Override
	boolean correct() {
		return false;
	}

	@Override
	Set<List<E>> words() {
		return Set.of();
	}
}
