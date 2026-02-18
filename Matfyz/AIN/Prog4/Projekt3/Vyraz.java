public abstract class Vyraz {
	
	public abstract double eval(double[] interpretacia);
	
	public abstract String toString();

	/**
	 * Priklad: Vypocita pravdepodobnost ze budem meskat. Meskam ked mi nezvoni
	 * budik alebo je zapcha.
	 * @param budikZvoni pravdepodobnost ze budik zvoni ako ma
	 * @param zapcha pravdepodobnost ze je zapcha
	 * @return pravdepodobnost ze budem meskat
	 */


	public static double budemMeskat(double budikZvoni, double zapcha) {
//		return -1;
//////// TENTO KOD SI ODKOMENTUJTE, KED UZ BUDETE MAT IMPLEMENTOVANE TRIEDY And, Or, ... SU NA KONCI TOHOTO SUBORU
//////// TENTO KOD SI ODKOMENTUJTE, KED UZ BUDETE MAT IMPLEMENTOVANE TRIEDY And, Or, ... SU NA KONCI TOHOTO SUBORU
//////// TENTO KOD SI ODKOMENTUJTE, KED UZ BUDETE MAT IMPLEMENTOVANE TRIEDY And, Or, ... SU NA KONCI TOHOTO SUBORU
//////// TENTO KOD SI ODKOMENTUJTE, KED UZ BUDETE MAT IMPLEMENTOVANE TRIEDY And, Or, ... SU NA KONCI TOHOTO SUBORU
		double[] interpretacia = new double[26];
		interpretacia['B' -'A'] = budikZvoni;  // premenna 'B'
		interpretacia['Z' -'A'] = zapcha;      // premenna 'Z'
		Vyraz x = new Or(
				new Not(new Premenna('B')),
				new Premenna('Z')
				);
		System.out.println(x);  // "(-B | Z)"
		return x.eval(interpretacia);
//	}
	}

	/**
	 * Vypocita pravdepodobnost ze budem mat Acko z Javy. Acko ziskam ked chodim
	 * na cvika, robim dobre ulohy a spravim dobre skusku.
	 * @param cvika ucast na cvikach
	 * @param ulohy uspesnost na ulohach
	 * @param skuska pravdepodobnost, ze spravim dobre skusku
	 * @return pravdepodobnost ze budem mat Acko z Javy
	 */
	public static double acko(double cvika, double ulohy, double skuska) {
		double[] interpretacia = new double[26];
		interpretacia['A' -'A'] = cvika;
		interpretacia['B' -'A'] = ulohy;
		interpretacia['C' -'A'] = skuska;
		Vyraz x = new And(
				new And(new Premenna('A'), new Premenna('B')),
				new Premenna('C')
		);

		return x.eval(interpretacia);
	}
	
	/**
	 * Vypocita pravdepodobnost, ze nespravim predmet Prg4. Neprejdem ked
	 * nechodim na cvika, alebo ked: nerobim dobre ulohy a zaroven nespravim
	 * dobre skusku.
	 * @param cvika ucast na cvikach
	 * @param ulohy uspesnost na ulohach
	 * @param skuska pravdepodobnost, ze spravim dobre skusku
	 * @return pravdepodobnost ze nespravim predmet Prg4
	 */
	public static double nespravimJavu(double cvika, double ulohy, double skuska) {
		double[] interpretacia = new double[26];
		interpretacia['A' -'A'] = cvika;
		interpretacia['B' -'A'] = ulohy;
		interpretacia['C' -'A'] = skuska;
		Vyraz x = new Or(
				new Not(new Premenna('A')),
				new And(new Not(new Premenna('B')), new Not(new Premenna('C')))
		);

		return x.eval(interpretacia);
	}
	
	public void zlyVstup() {
		throw new IllegalArgumentException("Zly vstup!");
	}



	public static void main(String[] args) {
		// tu si to mozete testovat
		double budikZvoni = 0.9;
		double zapcha = 0.6;
		System.out.println("Budem mestakt na " + budemMeskat(budikZvoni, zapcha)*100 + "%");  //64%
	}

}

//---------------------------- TRIEDA Konstanta
class Konstanta extends Vyraz {
	boolean hodnota;

	public Konstanta(boolean hodnota) {
		this.hodnota = hodnota;
	}

	@Override
	public double eval(double[] interpretacia) {
		if (hodnota) return 1;
		return 0;
	}

	@Override
	public String toString() {
		return Boolean.toString(hodnota).toUpperCase();
	}
}

//---------------------------- TRIEDA Premenna
class Premenna extends Vyraz {
	char meno;

	public Premenna(char meno) {
		if (meno < 'A' || meno > 'Z') {
			zlyVstup();
		}
		this.meno = meno;
	}

	@Override
	public double eval(double[] interpretacia) {
		if (interpretacia == null) zlyVstup();
		if (interpretacia.length != 26) zlyVstup();
		if (interpretacia[meno-'A'] < 0 || interpretacia[meno-'A'] > 1) zlyVstup();
		return interpretacia[meno - 'A'];
	}

	@Override
	public String toString() {
		return Character.toString(meno);
	}
}

//---------------------------- TRIEDA Not
class Not extends Vyraz {
	Vyraz x;

	public Not(Vyraz x) {
		if (x == null){
			zlyVstup();
		}
		this.x = x;
	}

	@Override
	public double eval(double[] interpretacia) {
		if (interpretacia == null) zlyVstup();
		if (interpretacia.length != 26) zlyVstup();

		return 1 - x.eval(interpretacia);
	}

	@Override
	public String toString() {
		return '-' + x.toString();
	}
}

//---------------------------- TRIEDA And
class And extends Vyraz {
	Vyraz x;
	Vyraz y;

	public And(Vyraz x, Vyraz y) {
		if (x == null || y == null) {
			zlyVstup();
		}

		this.x = x;
		this.y = y;
	}

	@Override
	public double eval(double[] interpretacia) {
		if (interpretacia == null) zlyVstup();
		if (interpretacia.length != 26) zlyVstup();

		return x.eval(interpretacia) * y.eval(interpretacia);
	}

	@Override
	public String toString() {
		return '(' + x.toString() + " & " + y.toString() + ')';
	}
}

//---------------------------- TRIEDA Or
class Or extends Vyraz {
	Vyraz x;
	Vyraz y;

	public Or(Vyraz x, Vyraz y) {
		if (x == null || y == null) {
			zlyVstup();
		}

		this.x = x;
		this.y = y;
	}

	@Override
	public double eval(double[] interpretacia) {
		if (interpretacia == null) zlyVstup();
		if (interpretacia.length != 26) zlyVstup();

		return (x.eval(interpretacia) + y.eval(interpretacia) - (x.eval(interpretacia) * y.eval(interpretacia)));
	}

	@Override
	public String toString() {
		return '(' + x.toString() + " | " + y.toString() + ')';
	}
}





