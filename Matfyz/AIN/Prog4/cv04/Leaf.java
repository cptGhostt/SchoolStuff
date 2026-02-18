record Leaf(int value) implements Tree {
    @Override
    public int size() {
        return 1;
    }

    @Override
    public int root() {
        return value;
    }

    @Override
    public boolean isBST() {
        return true;  // doprogramujte
    }
}