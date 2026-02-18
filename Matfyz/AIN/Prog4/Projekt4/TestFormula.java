import static org.junit.Assert.*;

import org.junit.Test;


public class TestFormula {
	// (( not(bit_1) || bit_0) && true)
	static Formula f1 = 
			new And(
					new Or(
							new Not(
									new Vstup(1)
									), 
							new Vstup(0)),
					new Konstanta(true)
					);
	
	// 	(bit_0 && (bit_1 && (bit_2 && (bit_3 && (bit_4 && (bit_5 && (bit_6 && (bit_7 && (bit_31 && true)))))))))
	static Formula f2 = 
			new And(
					new Vstup(0),
					new And(
							new Vstup(1),
							new And(
									new Vstup(2),
									new And(
											new Vstup(3),
											new And(
													new Vstup(4),
													new And(
															new Vstup(5),
															new And(
																	new Vstup(6),
																	new And(
																			new Vstup(7),
																			new And(
																			new Vstup(31),
																			new Konstanta(true))))))))));

	// ( not(bit_16) || bit_16)
	static Formula f3 = 
			new Or(
					new Not(
							new Vstup(16)
							), 
					new Vstup(16));
	
	// true
	static Formula f4 =
			new Konstanta(true);
	
	@Test
	public void test() {
		System.out.println(f1);
		assertEquals(f1+".hodnota(0)=", true, f1.hodnota(0));
		assertEquals(f1+".hodnota(2)=", false, f1.hodnota(2));
		assertEquals(f2+".hodnota(0)=", false, f2.hodnota(0));
		assertEquals(f2+".hodnota(-1)=", true, f2.hodnota(-1));
		assertEquals(f3+".hodnota(0)=", true, f3.hodnota(0));
		assertEquals(f3+".hodnota(-1)=", true, f3.hodnota(-1));

		System.out.println(f2);
		assertEquals(f1+".vsetkyVstupy=", 3, f1.vsetkyVstupy());
		assertEquals(f2+".vsetkyVstupy=", 0x800000FF, f2.vsetkyVstupy());
		
		System.out.println(f3);		
		assertEquals(f1+".tautologia()=", false, f1.tautologia());
		assertEquals(f2+".tautologia()=", false, f2.tautologia());
		assertEquals(f3+".tautologia()=", true, f3.tautologia());

		System.out.println(f4);
		assertEquals(f4+".tautologia()=", true, f4.tautologia());
	}
}
