public class Sedemciferne {
  /*
  * číslo som hľadal ručne pomocou pera a papiera následovne:
  * chceme aby číslo bolo čo najväčšie, tak som začal čislom 9 na prvej pozícii,
  * aby som dodržal deliteľnosť deviatkou, tak som postupne pridával čísla ktorých súčet je dokopy 9
  * tak, že väčšie z nich som dal na voľnú pozíciu v ľavo a menšie na pozíciu v pravo
  * dostalo som číslo 9876321, to ale nebolo párne, teda nebolo deliťeľné dvomi, tak som vymenil jednotku a dvojku
  * dostal som číslo 9876312, to ale stále nebolo deliteľné sedmičkou, tak som vymenil čśila 6 a 7
  * a dostal som požadované číslo
  */

  public static int najvacsie7() {
      return 9867312;
  }

  public static void main(String[] args) {
      System.out.println(najvacsie7());
  }
}