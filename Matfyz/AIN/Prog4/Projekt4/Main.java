
public class Main {
	/** Zoznam prvocisel vhodnych pre RSA. */
	public static final int[] PRIMES = {17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
			79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
			173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251};
	
	/**
	 * Vypocita (x^e) % m, tak ze nepretecie integer/long.
	 * @param x zaklad
	 * @param e exponent
	 * @param m modulo
	 */
	public static int powMod(int x, int e, int m) {
		if (e < 0 || m < 0) { return -1; }
		if (m == 1) { return 0; }
		long c = 1;
		for (int i = 0; i < e; i++) { 
			c = (c * x) % m;
		}
		return (int)c;
	}

	/** Ukazka pouzitia sifrovacich metod. */
	public static void main(String[] args) {
		// Symetricka sifra - obaja musia poznat rovnaky tajny kluc
		Sifra alica = new SymetrickaSifra("helloworld");	// new CezarovaSifra();
		Sifra bob   = new SymetrickaSifra("helloworld");	// new CezarovaSifra();
		
		// Alica posiela Bobovi zasifrovanu spravu
		String sprava      = "Odpoved na zakladnu otazku je 42.";
		String sifrovane   = alica.zasifruj(sprava);
		String desifrovane = bob.desifruj(sifrovane);
		System.out.println("Sprava: '"+sprava+"'\nSifrovane: '"+sifrovane+"'\nDesifrovane: '"+desifrovane+"'");
		
		
		// === RSA ===
		RSA alicaRsa = new RSA();
		RSA bobRsa   = new RSA();
		
		// Alica posiela Bobovi zasifrovanu spravu
		sifrovane   = alicaRsa.zasifrujCudzie(sprava, bobRsa.getPubKey());
		desifrovane = bobRsa.desifruj(sifrovane);
		System.out.println("\n=== RSA ===\nSprava: '"+sprava+"'\nSifrovane: '"+sifrovane+"'\nDesifrovane: '"+desifrovane+"'");
		
		// Alica si chce nechat tajomstvo pre seba
		sifrovane   = alicaRsa.zasifruj(sprava);
		desifrovane = alicaRsa.desifruj(sifrovane);
		String odsifBob = bobRsa.desifruj(sifrovane);
		System.out.println("\n=== RSA - tajomstvo ===\nSprava: '"+sprava+"'\nSifrovane: '"+sifrovane+"'\nDesifrovane: '"+desifrovane+"'\nBob sa snazil, ale neprecital: '" + odsifBob + "'");
	}

}
