sealed interface Tree permits Node, Leaf {
    int size();
    int root();
    boolean isBST();  // doprogramujte
}