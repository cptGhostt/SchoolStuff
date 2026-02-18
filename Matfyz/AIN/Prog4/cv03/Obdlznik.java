public class Obdlznik extends DvaD {
	public Bod2D lavyDolny;
	public double dx, dy;
	
	public Obdlznik(Bod2D lavyDolny, double dx, double dy) {
		super();
		this.lavyDolny = lavyDolny;
		this.dx = dx;
		this.dy = dy;
	}
	/**
	 * definujte obsah obdlznika
	 */
	@Override
	public double obsah() {
		return dx * dy;
	}
	/**
	 * definujte obvod obdlznika
	 */
	@Override
	public double obvod() {
		return 2*dx + 2*dy;
	}
	/**
	 * definujte test, ci bod b je v obdlzniku, alebo na jeho stranach
	 */
	@Override
	public boolean jeV(Bod2D b) {
		double x1 = lavyDolny.getX();
		double y1 = lavyDolny.getY();
		double x2 = x1+dx;
		double y2 = y1+dy;

		if (x1 <= b.getX() && x2 >= b.getX() && y1 <= b.getY() && y2 >= b.getY()) {
			return true;
		}

		return false;
	}
	/**
	 * posunite oblznika o vektor b
	 */
	@Override
	public void posun(Bod2D b) {
		lavyDolny.setX(lavyDolny.getX()+b.getX());
		lavyDolny.setY(lavyDolny.getY()+b.getY());
	}
}
