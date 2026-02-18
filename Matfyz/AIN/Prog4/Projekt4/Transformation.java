public interface Transformation {
	public Point apply(Point p);  // aplikuje trans. na dany bod a vrati vysledok
	public Transformation inverse();  // vrati inverznu transformaciu
}
