import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.BeforeClass;
import org.junit.Test;


public class TestVyraz {


	@SuppressWarnings("unused")
	@Test
	public final void testChybneVstupy() {		
		///////////////// Premenna /////////////////
		boolean ok = false;
		try{ Premenna x = new Premenna('*'); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("Premenna(char c) - vstup nie je 'A'-'Z'", ok);
		
		ok = false;
		try{ Premenna x = new Premenna('q'); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("Premenna(char c) - vstup je lowercase (mena premennych mozu byt iba uppercase)", ok);
		
		///////////////// Not /////////////////
		ok = false;
		try{ Not x = new Not(null); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("Not(Vyraz x) - vstup je null", ok);
		
		///////////////// And /////////////////
		Konstanta a = new Konstanta(true);
		ok = false;
		try{ And x = new And(a, null); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("And(Vyraz x, Vyraz y) - vstup je null", ok);
		
		ok = false;
		try{ And x = new And(null, a); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("And(Vyraz x, Vyraz y) - vstup je null", ok);
		
		///////////////// Or /////////////////
		ok = false;
		try{ Or x = new Or(a, null); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("Or(Vyraz x, Vyraz y) - vstup je null", ok);
		
		ok = false;
		try{ Or x = new Or(null, a); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("Or(Vyraz x, Vyraz y) - vstup je null", ok);
		
		
		///////////////// Interpretacia /////////////////
		Vyraz x = new Or(new Premenna('A'), new Premenna('B'));
		double[] interpretacia = null;		
		ok = false;
		try{ x.eval(interpretacia); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("eval(double[] i) - interpretacia je null", ok);
		
		interpretacia = new double[0];		
		ok = false;
		try{ x.eval(interpretacia); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("eval(double[] i) - interpretacia je prazdne pole", ok);
		
		interpretacia = new double[10];		
		ok = false;
		try{ x.eval(interpretacia); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("eval(double[] i) - interpretacia ma menej ako 26 prvkov", ok);
		
		interpretacia = new double[27];		
		ok = false;
		try{ x.eval(interpretacia); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("eval(double[] i) - interpretacia ma viac ako 26 prvkov", ok);
		
		interpretacia = new double[26];
		interpretacia[1] = -1.0;
		ok = false;
		try{ x.eval(interpretacia); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("eval(double[] i) - interpretacia obsahuje zaporne cislo", ok);
		
		interpretacia = new double[26];
		interpretacia[1] = 1.5;
		ok = false;
		try{ x.eval(interpretacia); }
		catch(IllegalArgumentException e) { ok = true; }
		assertTrue("eval(double[] i) - interpretacia obsahuje cislo > 1.0", ok);

	}

	
	@Test
	public final void testAcko() {
		double[][] in = {
				{0.9, 0.9, 0.9},
				{0.0, 1.0, 1.0},
				{0.1, 0.1, 0.1},
				{0.9, 0.6, 0.4}};
		double[] exp = {0.729, 0.0, 0.001, 0.216};
		
		for (int i = 0; i < in.length; i++) {
			double res = Vyraz.acko(in[i][0], in[i][1], in[i][2]);
			assertTrue("acko("+in[i][0] +","+ in[i][1] +","+ in[i][2]+")="+res+", expected="+exp[i], epsilonEq(res, exp[i]));
		}
	}
	
	@Test
	public final void testNespravimJavu() {
		double[][] in = {
				{0.9, 0.9, 0.9},
				{0.0, 1.0, 1.0},
				{0.1, 0.1, 0.1},
				{0.9, 0.6, 0.4}};
		double[] exp = {0.109, 1.0, 0.981, 0.316};
		
		for (int i = 0; i < in.length; i++) {
			double res = Vyraz.nespravimJavu(in[i][0], in[i][1], in[i][2]);
			assertTrue("nespravimJavu("+in[i][0] +","+ in[i][1] +","+ in[i][2]+")="+res+", expected="+exp[i], epsilonEq(res, exp[i]));
		}
	}

	
	///////////////// Definicia dvoch vyrazov /////////////////
	String xStr = "((-A | FALSE) & -(TRUE & (A | -C)))";
	Vyraz x = new And(
			new Or(
					new Not(new Premenna('A')),
					new Konstanta(false)
					),
			new Not(new And(
					new Konstanta(true),
					new Or(
						new Premenna('A'),
						new Not(new Premenna('C'))
						)
					))
			);
	
	String cnfStr = "((A | -B) & (B | C))";
	Vyraz cnf = new And(
			new Or(
					new Premenna('A'),
					new Not(new Premenna('B'))
					),
			new Or(
					new Premenna('B'),
					new Premenna('C')
					)
			);
	
	@Test
	public final void testEval() {
		double[] interpretacia = new double[26];
		interpretacia[0] = 0.75; interpretacia[1] = 0.25; interpretacia[2] = 0.33;
		
		double res = x.eval(interpretacia), exp = 0.020625;
		assertTrue("eval("+xStr+")="+res+", expected="+exp, epsilonEq(res, exp));
		
		res = cnf.eval(interpretacia); exp = 0.46640625;
		assertTrue("eval("+cnfStr+")="+res+", expected="+exp, epsilonEq(res, exp));
	}

	@Test
	public final void testToString() {
		assertEquals("toString(x)", xStr, x.toString());
		assertEquals("toString(cnf)", cnfStr, cnf.toString());
	}

	
	
	private static boolean epsilonEq(double a, double b){
		return Math.abs(a - b) < 0.000001;
	}

}
