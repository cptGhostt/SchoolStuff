public class Main {
    public static void main(String[] args) {
        Tree t = new Leaf(0);
        for (int i = 1; i < 1_000_000; i++)
            t = new Node(t, 2*i, new Leaf( 2*i+1));

//        System.out.println(t.size());
//        System.out.println(t.isBST());
        System.out.println(new Node(new Leaf(1),2, new Leaf(3)).isBST());
        System.out.println(new Node(new Leaf(2),1, new Leaf(3)).isBST());
        System.out.println(new Node(null,2, new Leaf(3)).isBST());
        //System.out.println(t.isBST());
    }
}
