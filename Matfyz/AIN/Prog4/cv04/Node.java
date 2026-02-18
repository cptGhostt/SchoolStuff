import java.util.ArrayList;
import java.util.Stack;

record Node(Tree left, int value, Tree right) implements Tree {
    @Override
    public int size() {
        // return 1 + ((left == null)?0:left.size()) + ((right == null)?0:right.size());

        int count = 0;
        Stack<Tree> stack = new Stack<>();
        stack.push(this);

        while (!stack.isEmpty()) {
            Tree current = stack.pop();

            if (current instanceof Node node) {
                count++;
                if (node.right != null) stack.push(node.right);
                if (node.left != null) stack.push(node.left);
            } else if (current instanceof Leaf) {
                count++;
            }
        }

        return count;
    }

    @Override
    public int root() {
        return value;
    }

    @Override
    public boolean isBST() {
        Stack<Tree> stack = new Stack<>();
        ArrayList<Integer> nodes = new ArrayList<>();
        nodes.add(Integer.MIN_VALUE);
        stack.push(this);

        while (!stack.isEmpty()) {

            if (stack.peek() instanceof Node node) {
                if (node.left != null) stack.push(node.left);
                else stack.push(null);
            }
            else if (stack.peek() == null){
                stack.pop();
                if (stack.isEmpty()) break;
                if (stack.pop() instanceof Node node) {
                    nodes.add(node.value);
                    if (nodes.get(nodes.size() - 1) <= nodes.get(nodes.size() - 2)) return false;
                    if (node.right != null) stack.push(node.right);
                    else stack.push(null);
                }
            }
            else  {
                nodes.add(stack.pop().root());
                if (nodes.get(nodes.size() - 1) <= nodes.get(nodes.size() - 2)) return false;
                if (stack.isEmpty()) break;
                if (stack.pop() instanceof Node node) {
                    nodes.add(node.root());
                    if (nodes.get(nodes.size() - 1) <= nodes.get(nodes.size() - 2)) return false;
                    if (node.right != null) stack.push(node.right);
                    else stack.push(null);
                }
            }
        }


        return true;
    }
}
