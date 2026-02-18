import java.util.*;

public class Zatvorky {
    public static boolean dobreUzatvorkovany(String s){
        Set<Character> chars = new HashSet<>(Set.of('(', ')', '[', ']', '{', '}', '<', '>'));
        Map<Character, Integer> map = new HashMap<>();

        for (char c : s.toCharArray()) {
            if (chars.contains(c)) {
                map.put(c, map.getOrDefault(c, 0) + 1);
            }else return false;
        }

        if (!map.get('(').equals(map.get(')'))) return false;
        if (!map.get('[').equals(map.get(']'))) return false;
        if (!map.get('{').equals(map.get('}'))) return false;
        if (!map.get('<').equals(map.get('>'))) return false;

        return true;
    }

    public static String dopln(String s){
        Set<Character> chars = new HashSet<>(Set.of('(', ')', '[', ']', '{', '}', '<', '>'));
        Map<Character, Character> matching = new HashMap<>(Map.of('(', ')', '[', ']', '{', '}', '<', '>'));
        Stack<Character> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (chars.contains(c)) {
                if (matching.containsKey(c)) stack.push(c);
                else {
                    if (stack.isEmpty()) return null;
                    char last = stack.pop();
                    if (matching.get(last) != c) return null;
                }
            }else return null;
        }

        while (!stack.isEmpty()) sb.append(matching.get(stack.pop()));

        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(dopln("{<{<{[<[{{([{{{}()}<{}()>}<[{}]>]<<{{}<>}([]<>)>[({}<>){()[]}]>)[[([(){}][<><>])<<()>{()()}>]]}}[(<{[(<>"));

    }
}
