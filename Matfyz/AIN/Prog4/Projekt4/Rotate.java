public class Rotate extends Matrix implements Transformation {
    private double angle;

    public Rotate(double angle) {
        super(3);
        m[0][0] = Math.cos(angle);
        m[0][1] = -Math.sin(angle);
        m[1][0] = Math.sin(angle);
        m[1][1] = Math.cos(angle);
        this.angle = angle;
    }

    @Override
    public Point apply(Point p) {
        return new Point(times(p));
    }

    @Override
    public Transformation inverse() {
        // toto mam odtial: https://www.graphics.stanford.edu/courses/cs248-98-fall/Final/q4.html
        return new Rotate(-angle);
    }
}
