import LISTTestScoring.LISTTestScoring;
import org.junit.BeforeClass;

import static org.junit.Assert.*;

import org.junit.Test;

public class TestFormula2 {
	private static LISTTestScoring scoring = null;

	@BeforeClass
	public static void initScoring() {
		scoring = new LISTTestScoring();
		scoring.setScore("lang:common_list_test_scoring_name", 0, 100);
	}

	// (( not(bit_1) || bit_0) && true)
	static Formula f1 = new And(new Or(new Not(new Vstup(1)), new Vstup(0)),
			new Konstanta(true));

	// (bit_0 && (bit_1 && (bit_2 && (bit_3 && (bit_4 && (bit_5 && (bit_6 &&
	// (bit_7 && (bit_31 && true)))))))))
	static Formula f2 = new And(new Vstup(0), new And(new Vstup(1), new And(
			new Vstup(2), new And(new Vstup(3), new And(new Vstup(4), new And(
					new Vstup(5), new And(new Vstup(6), new And(new Vstup(7),
							new And(new Vstup(31), new Konstanta(true))))))))));

	// ( not(bit_16) || bit_16)
	static Formula f3 = new Or(new Not(new Vstup(16)), new Vstup(16));

	// true
	static Formula f4 = new Konstanta(true);

	// false
	static Formula f5 = new Vstup(31);

	// false
	static Formula f6 = new Or(new Vstup(31), new Vstup(0));

	// false
	static Formula f7 = new Or(new Vstup(31), new Vstup(30));

	// true
	static Formula f8 = new Or(new Vstup(31), new Not(new Vstup(31)));

	// false
	static Formula f9 = new Not(new Vstup(31));
	// false
    static Formula f10 = new Or(new Not(new Vstup(1)), new Not(new Vstup(15)));
	// false
    static Formula f11 = new Or(new Not(new Vstup(3)), new Not(new Vstup(28)));
	// false
    static Formula f12 = new Or(new Not(new Vstup(4)), new Not(new Vstup(5)));


	@Test
	public void test() {
		System.out.println(f1);
		assertEquals(f1 + ".hodnota(0)=", true, f1.hodnota(0));
		assertEquals(f1 + ".hodnota(2)=", false, f1.hodnota(2));
		assertEquals(f2 + ".hodnota(0)=", false, f2.hodnota(0));
		assertEquals(f2 + ".hodnota(-1)=", true, f2.hodnota(-1));
		assertEquals(f3 + ".hodnota(0)=", true, f3.hodnota(0));
		assertEquals(f3 + ".hodnota(-1)=", true, f3.hodnota(-1));

		System.out.println(f2);
		assertEquals(f1 + ".vsetkyVstupy=", 3, f1.vsetkyVstupy());
		assertEquals(f2 + ".vsetkyVstupy=", 0x800000FF, f2.vsetkyVstupy());

		System.out.println(f3);
		assertEquals(f1 + ".tautologia()=", false, f1.tautologia());
		assertEquals(f2 + ".tautologia()=", false, f2.tautologia());
		assertEquals(f3 + ".tautologia()=", true, f3.tautologia());

		System.out.println(f4);
		assertEquals(f4 + ".tautologia()=", true, f4.tautologia());
        
   		System.out.println(f5);
		assertEquals(f5 + ".tautologia()=", false, f5.tautologia());

   		System.out.println(f6);
		assertEquals(f6 + ".tautologia()=", false, f6.tautologia());
        
   		System.out.println(f7);
		assertEquals(f7 + ".tautologia()=", false, f7.tautologia());
        
   		System.out.println(f8);
		assertEquals(f8 + ".tautologia()=", true, f8.tautologia());

   		System.out.println(f9);
		assertEquals(f9 + ".tautologia()=", false, f9.tautologia());
        
   		System.out.println(f10);
		assertEquals(f10 + ".tautologia()=", false, f10.tautologia());
        
   		System.out.println(f11);
		assertEquals(f11 + ".tautologia()=", false, f11.tautologia());
        
  		System.out.println(f12);
		assertEquals(f12 + ".tautologia()=", false, f12.tautologia());

		TestFormula2.scoring.updateScore("lang:common_list_test_scoring_name",20);

	}

	@Test
	public void test1() {
		Formula f = gener(10);
		System.out.println(f);
		assertEquals(f + ".hodnota(0)=", true, f.hodnota(0));
		assertEquals(f + ".vsetkyVstupy(0)=", 0, f.vsetkyVstupy());
		assertEquals(f + ".tautologia()=", true, f.tautologia());
		TestFormula2.scoring.updateScore("lang:common_list_test_scoring_name",20);
	}
	
	@Test
	public void test2() {
		Formula f = gener1(10);
		System.out.println(f);
		assertEquals(f + ".hodnota(0)=", true, f.hodnota(0));
		assertEquals(f + ".vsetkyVstupy(0)=", 1023, f.vsetkyVstupy());
		assertEquals(f + ".tautologia()=", true, f.tautologia());
		TestFormula2.scoring.updateScore("lang:common_list_test_scoring_name",20);
	}

	@Test
	public void test3() {
		Formula f = new And(gener1(10), gener(10));
		System.out.println(f);
		assertEquals(f + ".hodnota(0)=", true, f.hodnota(0));
		assertEquals(f + ".vsetkyVstupy(0)=", 1023, f.vsetkyVstupy());
		assertEquals(f + ".tautologia()=", true, f.tautologia());
		TestFormula2.scoring.updateScore("lang:common_list_test_scoring_name",20);
	}

	@Test
	public void test4() {
		Formula f = gener2(10);
		System.out.println(f);
		assertEquals(f + ".hodnota(0)=", false, f.hodnota(0));
		assertEquals(f + ".vsetkyVstupy(0)=", 1023, f.vsetkyVstupy());
		assertEquals(f + ".tautologia()=", false, f.tautologia());
		TestFormula2.scoring.updateScore("lang:common_list_test_scoring_name",20);
	}
	
	
	private Formula gener(int i) {
		if (i == 0)
			return new Konstanta(true);
		else
			return new And(gener(i - 1), gener(i - 1));
	}

	private Formula gener1(int i) {
		if (i == 0)
			return new Konstanta(true);
		else
			return new And(new Or(new Vstup(i - 1), new Not(new Vstup(i - 1))),
					new And(gener1(i - 1), gener1(i - 1)));
	}
	
	private Formula gener2(int i) {
		if (i == 0)
			return new Konstanta(false);
		else
			return new And(new Or(new Vstup(i - 1), new Not(new Vstup(i - 1))),
					new And(gener2(i - 1), gener2(i - 1)));
	}
}

