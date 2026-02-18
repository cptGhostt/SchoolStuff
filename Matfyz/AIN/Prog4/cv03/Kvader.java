public class Kvader extends TriD {
	public Bod3D lavyDolny;
	public double dx, dy, dz;

	public Kvader(Bod3D lavyDolny, double dx, double dy, double dz) {
		super();
		this.lavyDolny = lavyDolny;
		this.dx = dx;
		this.dy = dy;
		this.dz = dz;
	}
	/**
	 * definujte objem kvadra 
	 */
	@Override
	public double objem() {
		return dx*dy*dz;
	}
	/**
	 * definujte povrch kvadra 
	 */
	@Override
	public double povrch() {
		return 2*dx*dy + 2*dx*dz + 2*dy*dz;
	}
	/**
	 * definujte test, ci bod b je v kvadri 
	 */
	@Override
	public boolean jeV(Bod3D b) {
		double x1 = lavyDolny.getX();
		double y1 = lavyDolny.getY();
		double z1 = lavyDolny.getZ();
		double x2 = x1+dx;
		double y2 = y1+dy;
		double z2 = y1+dz;

		if (x1 <= b.getX() && x2 >= b.getX() && y1 <= b.getY() && y2 >= b.getY() && z1 <= b.getZ() && z2 >= b.getZ()) {
			return true;
		}

		return false;
	}
	/**
	 * definujte posunutie kvadra o vektor b 
	 */
	@Override
	public void posun(Bod3D b) {
		lavyDolny.setX(lavyDolny.getX()+b.getX());
		lavyDolny.setY(lavyDolny.getY()+b.getY());
		lavyDolny.setZ(lavyDolny.getZ()+b.getZ());
	}
}
