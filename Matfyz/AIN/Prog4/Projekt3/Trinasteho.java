import java.util.Arrays;

public class Trinasteho {

    public static void main(String[] args) {

        int day = 5; // 13ho v decembri 2025 bude sobota
        int[] offsets = {3, 3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2}; // počet dni o koľko sa posunuú dni v týždni ak sa posúvam o mesiac späť
                                                              // ak bol 13. januára napríklad štvrtok, tak 13. decembra bol pondelok
        int[] daysOfWeek = new int[7];
        int year = 2025;

        // https://scienceworld.wolfram.com/astronomy/FridaytheThirteenth.html
        // podľa tohto zdroja, 13. v mesiaci najčastejšie padne na piatok a "cyklus" opakuje každých 400 rokov
        // ak pojdem 400 rokov dozadu (teda môj cyklus bude vyzerať while (year > 1625)), tak sa moje dáta zhoduju s tými ich
        // a teda som si potvrdil že to je pravda a môžem spokojne tvrdiť že 13. naaozaj padne najčastejšie na piatok

        // cyklus v tejto podobe počíta výskyt 13. od začiatku gregoriánskeho kalendára po koniec roku 2025
        while (year > 1581) {

            for (int i = 11; i >= 0; i--) {
                daysOfWeek[day % 7]++;

                if (i == 2){
                    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                        day--;
                        if (day < 0) day += 7;
                    }
                } else {
                    day -= offsets[i];
                    if (day < 0) day += 7;
                }

                // začiatok gregorianskeho kalendára bol 15.10.1582
                // kedže v október začal až 15. dňom, tak ten už počítať nechcem
                if (year == 1582 && i == 10) break;
            }

            year--;
        }


        System.out.println(Arrays.toString(daysOfWeek));

    }

}
