abstract class DvaD {
	public abstract double obsah();
	public abstract double obvod();
	public abstract boolean jeV(Bod2D b);
	public abstract void posun(Bod2D b);

	// definujte konstantu obe, ktora obsahuje lubovolny obdlznik a kruh v lubovolnom poradi
	public static final DvaD[] obe = {new Kruh(new Bod2D(0, 0), 1),
									 new Obdlznik(new Bod2D(5, 5), 10, 5)};
}
