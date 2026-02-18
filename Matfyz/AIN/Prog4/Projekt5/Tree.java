import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

public class Tree {
    Node root;

    public Tree(Node root) {
        this.root = root;
    }

    public boolean isOneTypeOfFruitOnNode() {
        Stack<Node> stack = new Stack<Node>();
        stack.push(root);

        while (!stack.isEmpty()) {
            Node node = stack.pop();
            Set<Class> classes = new HashSet<>();

            for (Object fruit : node.fruits) {
                if (fruit == null) continue;
                classes.add(fruit.getClass());
            }
            if (classes.size() > 1) return false;

            if (node.left != null) stack.push(node.left);
            if (node.right != null) stack.push(node.right);
        }

        return true;
    }

    public boolean isSameOneTypeOfFruitOnChildren() {
        Stack<Node> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            Node node = stack.pop();
            Set<Class> classes = new HashSet<>();

            if (node.left != null) {
                stack.push(node.left);
                for (Object fruit : node.left.fruits) {
                    if (fruit == null) continue;
                    classes.add(fruit.getClass());
                }
            }
            if (node.right != null) {
                stack.push(node.right);
                for (Object fruit : node.right.fruits) {
                    if (fruit == null) continue;
                    classes.add(fruit.getClass());
                }
            }
            if (classes.size() > 1) return false;

        }
        return true;
    }
}
