public class Point extends Matrix {

    public Point (double x, double y) {
        super(3, 1);
        m[0][0] = x;
        m[1][0] = y;
        m[2][0] = 1;
    }

    public Point (Matrix matrix) {
        super(3, 1);
        if (matrix.rows != 3 || matrix.cols != 1) {
            zlyVstup();
        }

        m[0][0] = matrix.m[0][0];
        m[1][0] = matrix.m[1][0];
        m[2][0] = matrix.m[2][0];
    }

    public Point transform(Transformation t) {
        return t.apply(this);
    }
}
