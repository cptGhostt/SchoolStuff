import java.util.ArrayList;

public class Geometricka {

    public static String find(){
        ArrayList<Double> bestArr = new ArrayList<>();

        for (int k = 10000; k < 100000; k++) {
            double i = 2.0;
            double j = 1.0;

            while (i/j > 1.01){
                double tmp = k;
                ArrayList<Double> tmpArr = new ArrayList<>();

                while (tmp < 100000){
                    if (tmp > (int)tmp) {
                        tmpArr.clear();
                        break;
                    }
                    tmpArr.add(tmp);
                    tmp *= i/j;
                }
                if(tmpArr.size() > bestArr.size()) {
                    bestArr = tmpArr;
                }
                i++;
                j++;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int x = 0; x < bestArr.size(); x++){
            if (x == 0) sb.append(bestArr.get(x).intValue());
            else {
                sb.append(',');
                sb.append(bestArr.get(x).intValue());
            }
        }
        return sb.toString();
    }

    public static String riesenie() {
        return find();
    }

    public static void main(String[] args) {
        System.out.println(riesenie());
    }
}
