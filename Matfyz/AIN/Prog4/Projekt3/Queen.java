record Queen(int n, int row, int col) {
    public boolean attacked(Queen q) {
        if (q.col == col || q.row == row) return true;
        if (Math.abs(q.col - col) == Math.abs(q.row - row)) return true;
        if (Math.abs(Math.abs(q.col - col) - n) == Math.abs(q.row - row)) return true;

        return false;
    }
}
