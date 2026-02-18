public class Translate extends Matrix implements Transformation {

    public Translate(double x, double y) {
        super(3);
        m[0][2] = x;
        m[1][2] = y;
    }

    @Override
    public Point apply(Point p) {
        return new Point(times(p));
    }

    @Override
    public Transformation inverse() {
        // toto mam odtial: https://www.graphics.stanford.edu/courses/cs248-98-fall/Final/q4.html
        return new Translate(-m[0][2], -m[1][2]);
    }
}
