import java.util.*;

public class DFA<S,A> {
    private Set<S> states;          // mnozina stavov
    private S initState;            // pociatocny stav
    private Set<A> alphabet;        // abeceda symbolov slova
    private Set<S> finalStates;     // mnozina koncovych/akceptujucich stavov
    private Map<S, Map<A, S>> delta; // delta funkcia, zobrazuje stav a pismenko na novy stav

    public DFA(Set<S> states, S initState, Set<A> alphabet, Set<S> finalStates, Map<S, Map<A, S>> delta) {
        this.states = states;
        this.initState = initState;
        this.alphabet = alphabet;
        this.finalStates = finalStates;
        this.delta = delta;
    }

    @Override
    public String toString() {
        return "DFA{" +
                "states=" + states +
                ", initState=" + initState +
                ", alphabet=" + alphabet +
                ", finalStates=" + finalStates +
                ", delta=" + delta +
                '}';
    }

    public Set<S> getStates() {
        return states;
    }

    public S getInitState() {
        return initState;
    }

    public Set<A> getAlphabet() {
        return alphabet;
    }

    public Set<S> getFinalStates() {
        return finalStates;
    }

    public Map<S, Map<A, S>> getDelta() {
        return delta;
    }
    
    /**
     * tento kus kodu som vam nechal len preto, aby
     * som ilustroval, ze zistit, ci automat akceptuje
     * dane vstupne slovo je uplne priamociare, a aj
     * ako ilustraciu na pracu so strukturami automatu
     */
    public boolean accept(List<A> word) {
        S s = initState;
        // nerad indexujem
        for (A ch : word)
            s = delta.get(s).get(ch);

        // rad indexujem
//        for (int i = 0; i < word.size(); i++)
//            s = delta.get(s).get(word.get(i));
        return finalStates.contains(s);
    }

    public boolean prazdny() {
        Stack<S> stack = new Stack<>();
        stack.push(initState);
        Set<S> visited = new HashSet<>();

        while (!stack.empty()) {
            S s = stack.pop();
            visited.add(s);
            if (finalStates.contains(s)) return false;
            for (A ch : alphabet){
                S tmp = delta.get(s).get(ch);
                if (!visited.contains(tmp)) stack.push(tmp);
            }
        }

        return true; // DU 6
    }

    public boolean koncovy(S state, Set<S> visited, Set<S> doKoncovych) {
        visited.add(state);
        boolean fin = finalStates.contains(state);
        for (A ch : alphabet){
            S s = delta.get(state).get(ch);
            if (!visited.contains(s)) fin = fin || koncovy(s, visited, doKoncovych);
        }
        if (fin) doKoncovych.add(state);
        return fin;
    }

    public boolean nekonecny() {
        Set<S> doKoncovych = new HashSet<>();
        koncovy(initState, new HashSet<>(), doKoncovych); // DU 6

        Stack<S> stack = new Stack<>();
        stack.push(initState);
        Set<S> visited = new HashSet<>();

        while (!stack.empty()) {
            S s = stack.pop();
            visited.add(s);
            Set<S> dalej = new HashSet<>();

            for (A ch : alphabet){
                S tmp = delta.get(s).get(ch);
                dalej.add(tmp);
            }

            for (S ss : dalej){
                if (!visited.contains(ss)) stack.push(ss);
                else if (doKoncovych.contains(ss)) return true;
            }
        }

        return false;
    }

    record Configuration<S, A>(S state, List<A> word){}
    public Set<List<A>> language(int len) {
        Set<List<A>> result = new HashSet<>();

        Stack<Configuration<S, A>> stack = new Stack<>();
        stack.push(new Configuration<S, A>(initState, new ArrayList<A>()));

        while (!stack.empty()) {
            Configuration<S, A> c = stack.pop();
            if (finalStates.contains(c.state)) result.add(c.word);

            for (A ch : alphabet) {
                S tmp = delta.get(c.state).get(ch);
                List<A> newWord = new ArrayList<>(c.word);
                newWord.add(ch);
                if (newWord.size() > len) continue;
                stack.push(new Configuration<S, A>(tmp, newWord));
            }
        }

        return result; // DU 6
    }

    public static void main(String[] args) {
        var dfa = new DFA<String, Character>(
                Set.of("a", "b", "c", "d"),
                "a",
                Set.of('0', '1'),
                Set.of("d"),
                Map.of("a", Map.of(
                                '0', "b",
                                '1', "a"),
                       "b", Map.of(
                                '0', "b",
                                '1', "c"),
                       "c", Map.of(
                                '0', "d",
                                '1', "a"),
                        "d", Map.of(
                                '0', "d",
                                '1', "d")

                )
        );
        System.out.println(dfa.accept(List.of('1','1','0','0','1','0','0','1')));
        System.out.println(dfa.language(10));
        System.out.println(dfa.prazdny());
        System.out.println(dfa.nekonecny());
    }
}
