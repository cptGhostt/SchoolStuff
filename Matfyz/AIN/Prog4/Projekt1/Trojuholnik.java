public class Trojuholnik {

    /** na to, aBy tri body tvorili trojuholnik,
        - ziadne dva z nich nesmu Byt rovnake
        - a nesmu Byt kolinearne, teda lezat na priamke
     */
    public static boolean jeTrojuholnik(double Ax, double Ay, double Bx, double By, double Cx, double Cy) {
        // kontrola totožnosti bodov
        if (Math.abs(Ax - Bx) < 0.0001 && Math.abs(Ay - By) < 0.0001) return false;
        if (Math.abs(Ax - Cx) < 0.0001 && Math.abs(Ay - Cy) < 0.0001) return false;
        if (Math.abs(Bx - Cx) < 0.0001 && Math.abs(By - Cy) < 0.0001) return false;

        // ak body ležia na jednej priamke, tak obsah takého "trojuholníka" bude 0
        if (Math.abs(obsah(Ax, Ay, Bx, By, Cx, Cy)) < 0.0001) return false;

        return true;
    }

    /** Pythagorova veta
     */
    public static boolean jePravouhly(double Ax, double Ay, double Bx, double By, double Cx, double Cy) {
        if (!jeTrojuholnik(Ax, Ay, Bx, By, Cx, Cy)) return false;
        double a = Math.sqrt((Bx - Ax)*(Bx - Ax) + (By - Ay)*(By - Ay));
        double b = Math.sqrt((Cx - Bx)*(Cx - Bx) + (Cy - By)*(Cy - By));
        double c = Math.sqrt((Ax - Cx)*(Ax - Cx) + (Ay - Cy)*(Ay - Cy));

        if (Math.abs(a*a + b*b - c*c) < 0.0001) return true;
        if (Math.abs(a*a + c*c - b*b) < 0.0001) return true;
        if (Math.abs(b*b + c*c - a*a) < 0.0001) return true;

        return false;
    }

    /** vsetky uhly ma ostre, teda < 90 stupnov
     */
    public static boolean jeOstrouhly(double Ax, double Ay, double Bx, double By, double Cx, double Cy) {
        if (!jeTrojuholnik(Ax, Ay, Bx, By, Cx, Cy)) return false;
        if (jePravouhly(Ax, Ay, Bx, By, Cx, Cy)) return false;
        double a = Math.sqrt((Bx - Ax)*(Bx - Ax) + (By - Ay)*(By - Ay));
        double b = Math.sqrt((Cx - Bx)*(Cx - Bx) + (Cy - By)*(Cy - By));
        double c = Math.sqrt((Ax - Cx)*(Ax - Cx) + (Ay - Cy)*(Ay - Cy));

        if (a*a - (b*b + c*c) > 0.0001) return false;
        if (b*b - (c*c + a*a) > 0.0001) return false;
        if (c*c - (a*a + b*b) > 0.0001) return false;

        return true;
    }

    /** spocitate dlzky stran, na co staci pythagorova veta, alebo euklidovska vzdialenost v rovine
     */
    public static double obvod(double Ax, double Ay, double Bx, double By, double Cx, double Cy) {
        double a = Math.sqrt((Bx - Ax)*(Bx - Ax) + (By - Ay)*(By - Ay));
        double b = Math.sqrt((Cx - Bx)*(Cx - Bx) + (Cy - By)*(Cy - By));
        double c = Math.sqrt((Ax - Cx)*(Ax - Cx) + (Ay - Cy)*(Ay - Cy));
        return a+b+c;
    }

    /** Heronov vzorec
     */
    public static double obsah(double Ax, double Ay, double Bx, double By, double Cx, double Cy) {
        return 0.5*Math.abs(Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By));
    }

    /** sucet obsahov trojuholnikov QAB, QBC, QAC dava spolu obsah ABC
     */
    public static boolean leziVTrojuholniku(double Qx, double Qy, double Ax, double Ay, double Bx, double By, double Cx, double Cy) {
        double S1 = obsah(Qx, Qy, Bx, By, Cx, Cy);
        double S2 = obsah(Ax, Ay, Qx, Qy, Cx, Cy);
        double S3 = obsah(Ax, Ay, Bx, By, Qx, Qy);
        double S = obsah(Ax, Ay, Bx, By, Cx, Cy);

        if (Math.abs(S1+S2+S3 - S) < 0.0001) return true;

        return false;
    }

    /** pocet mrezovych bodov (s celociselnymi suradnicami), ktore lezia uvnutri trojuholnika resp. na jeho stranach
     */
    public static int mrezoveBody(
            double Ax, double Ay, double Bx, double By, double Cx, double Cy) {
        // použil som Pickovu vetu o ktorej som sa dozvedel tu:
        // http://thales.doa.fmph.uniba.sk/sleziak/vyuka/2010/semtc/01pick.pdf
        // a  výpočet hodnoty B mi poradil chatGPT
        int B1 = gcd((int)Math.abs(Bx - Ax), (int)Math.abs(By - Ay));
        int B2 = gcd((int)Math.abs(Cx - Ax), (int)Math.abs(Cy - Ay));
        int B3 = gcd((int)Math.abs(Cx - Bx), (int)Math.abs(Cy - By));
        int B = B1 + B2 + B3;
        double S = obsah(Ax, Ay, Bx, By, Cx, Cy);
        if (Math.abs(S - 0.5) < 0.0001) return 3;
        int I = (int)(S - (B/2) + 1);


        return I + B;
    }

    // euklidov algoritmus
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        System.out.println(jeOstrouhly(0.0,0.0,3.0,0.0,0.0,4.0));
    }
}