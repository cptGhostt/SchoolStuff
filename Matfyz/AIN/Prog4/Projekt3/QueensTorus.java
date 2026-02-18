import java.util.Arrays;

public class QueensTorus {

    public static Queen[] solution(int n) {
        // to že daný problém nemá riešenie ak je n deliteľné dvomi alebo tromi som zistil tu:
        // https://www.johndcook.com/blog/2021/08/18/queens-on-a-donut/
        if (n % 2 == 0 || n % 3 == 0) return null;

        return rek(n, 0,new boolean[n], new boolean[2][2*n], new Queen[n]); // toto doprogramujte
    }

    public static Queen[] rek(int n, int row, boolean[] col, boolean[][] diagonal, Queen[] queens) {
        if (row == n) {
            for (int x = 0; x < n; x++) {
                for (int y = x+1; y < n; y++) {
                    if (queens[x].attacked(queens[y])) return null;
                }

            }
            return queens;
        }

        for (int j = 0; j < n; j++) {
            if (col[j] || diagonal[0][row + j] || diagonal[1][row - j + n]) continue;

            queens[row] = (new Queen(n, row, j));
            col[j] = true;

            // výpočet obsadených diagonal som našiel tu:
            // https://stackoverflow.com/questions/3209165/need-help-with-n-queens-program-checking-diagonals
            // veta v tretej odpovedi: Diagonals can be expressed in the form of y = x + c or y = c - x.
            diagonal[0][row + j] = true;
            diagonal[1][row - j + n] = true; // +n tam je len ako offset aby mi nevychádzali záporné indexy

            Queen[] tmp = rek(n, row+1, col, diagonal, queens);
            if (tmp != null) return tmp;

            queens[row] = null;
            col[j] = false;
            diagonal[0][row + j] = false;
            diagonal[1][row - j + n] = false;
        }

        return null;
    }

    public static void main(String[] args) {
        Queen q1= new Queen(5,0,0);
        Queen q2= new Queen(5,1,2);
        Queen q3= new Queen(5,2,4);
        Queen q4= new Queen(5,3,1);
        Queen q5= new Queen(5,4,3);
        Queen[] s = new Queen[]{q1,q2,q3,q4,q5};
        for(int i = 0; i<s.length; i++)
            for(int j = i+1; j<s.length; j++)
                if (s[i].attacked(s[j]))
                    System.out.println(i+","+j);

        System.out.println(Arrays.toString(solution(5)));
    }
}
