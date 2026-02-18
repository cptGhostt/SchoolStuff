import java.util.*;

public class KnightOrienteering {

    public static String getRoute(int sx, int sy, int[][] queens){
        StringBuilder sb = new StringBuilder();
        int[][] steps = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

        Set<String> visited = new HashSet<>();
        boolean[][] safe = new boolean[8][8];
        int toVisit = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (!isDangerous(i, j, queens)){
                    safe[i][j] = true;
                    toVisit++;
                }
            }
        }

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{sx, sy});
        visited.add(sx + "," + sy);
        toVisit--;

        while (!q.isEmpty() && toVisit > 0) {
            int[] cur = q.poll();

            sb.append(cur[0] + "," + cur[1] + ";");
            if (!visited.contains(cur[0] + "," + cur[1])){
                toVisit--;
                visited.add(cur[0] + "," + cur[1]);
            }
            if (toVisit == 0) break;

            for (int[] step : steps) {
                int[] next = {cur[0] + step[0], cur[1] + step[1]};
                if (next[0] < 0 || next[0] >= 8 || next[1] < 0 || next[1] >= 8 || !safe[next[0]][next[1]]) continue;
                int[] tmp = q.peek();
                if (tmp != null && !isViableMove(tmp[0], tmp[1], next[0], next[1])) q.offer(cur);
                q.offer(next);
            }

        }

        return sb.substring(4, sb.length() - 1);
    }

    public static boolean isViableMove(int x, int y, int a, int b){
        if (Math.abs(x - a) == 2 && Math.abs(y - b) == 1) return true;
        if (Math.abs(x - a) == 1 && Math.abs(y - b) == 2) return true;
        return false;
    }

    public static boolean isDangerous(int sx, int sy, int[][] queens){
        for(int[] q : queens){
            if (q[0] == sx || q[1] == sy) return true;
            if (q[0] + q[1] == sx + sy) return true;
            if (q[0] - q[1] == sx - sy) return true;
        }

        return false;
    }

    public static void main(String[] args) {
        System.out.println(getRoute(0,0, new int[][]{{1,3}, {3,4}, {4,2}, {5,6}, {6,7}, {7,5}})); // should be : 2,1
        System.out.println(getRoute(0,0, new int[][]{{1,4}, {3,4}, {5,3}, {5,6}, {6,7}, {7,5}, {5,2}})); // should be: 2,1;4,0
        System.out.println(getRoute(4, 4, new int[][]{{0, 7}, {1, 2}, {1, 6}, {2, 0}, {3, 1}, {5, 1}, {7, 0}})); // should be: 6,5;4,4;6,3 or: 6,3;4,4;6,5
    }

}
