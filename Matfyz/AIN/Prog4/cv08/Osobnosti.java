import java.util.*;
import java.io.*;
import java.util.regex.*;

public class Osobnosti {
    /**
     * konvertuje String mesiaca na int
     */
    private  static int monthConvertor(String m) {
        switch (m) {
            case "januara":
            case "januar":
            case "januára":
            case "január":
                return 0;
            case "februara":
            case "februar":
            case "februára":
            case "február":
                return 1;
            case "marca":
            case "marec":
                return 2;
            case "aprila":
            case "april":
            case "apríla":
            case "apríl":
                return 3;
            case "maja":
            case "maj":
            case "mája":
            case "máj":
                return 4;
            case "juna":
            case "jun":
            case "júna":
            case "jún":
                return 5;
            case "jula":
            case "jul":
            case "júla":
            case "júl":
                return 6;
            case "augusta":
            case "august":
                return 7;
            case "septembra":
            case "september":
                return 8;
            case "oktobra":
            case "oktober":
                return 9;
            case "novembra":
            case "november":
                return 10;
            case "decembra":
            case "december":
                return 11;
            default:
                int i = m.indexOf('.');
                if (i != -1) {
                    m = m.substring(0, i);
                    try{
                        return Integer.parseInt(m);
                    } catch(NumberFormatException e){
                        return 0;
                    }
                }
        }
        return 0;
    }
    /**
     * vyrobi Date z troch stringov
     */
    private static Date makeDate(String yyyy, String month, String dd) {
        return new GregorianCalendar(
                            Integer.parseInt(yyyy),
                            monthConvertor(month),
                            Integer.parseInt(dd)
                    ).getTime();
    }
    // vráti niektorý z najčastejších dátumov v súbore
    public static Date najcastejsiDatum(String fileName) {
        List<Date> dates = new ArrayList<>();

        try {
            Scanner sc = new Scanner(new FileInputStream(new File(fileName)));

            Pattern pattern = Pattern.compile("(\\d{1,2})\\.\\s*(\\d{1,2}\\.|[\\p{L}]+)\\s*(\\d{4})");
            while (sc.hasNextLine()) {
                String line = sc.nextLine().toLowerCase();
                Matcher matcher = pattern.matcher(line);
                while (matcher.find()) {
                    //System.out.println(matcher.group(0) + " ... " + matcher.group(1) + " " + matcher.group(2) + " " + matcher.group(3) + " ");
                    Date date = makeDate(matcher.group(3), matcher.group(2), matcher.group(1));
                    dates.add(date);
                }
            }

            System.out.println();
        } catch (IOException ee) {}

        Map<Date, Integer> freq = new HashMap<>();
        for(var date: dates) {
            freq.put(date, freq.getOrDefault(date, 0) + 1);
        }

        int max = 0;
        Date maxDate = null;
        for (var entry: freq.entrySet()) {
            Date date = entry.getKey();
            int count = entry.getValue();
            if (count > max) {
                max = count;
                maxDate = date;
            }
        }

        return maxDate;
    }
    public static void main(String[] args) {
        System.out.println(najcastejsiDatum("osobnosti.txt"));
    }
}
