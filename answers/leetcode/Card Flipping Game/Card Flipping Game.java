import java.util.SortedSet;

class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        HashSet<Integer> both = new HashSet<>();
        SortedSet<Integer> numbers = new TreeSet<>();
        for (int i = 0; i < fronts.length; i++) {
            numbers.add(fronts[i]);
            numbers.add(backs[i]);
            if (fronts[i] == backs[i]) {
                both.add(fronts[i]);
            }
        }
        for (int number : numbers) {
            if (!both.contains(number)) {
                return number;
            }
        }
        return 0;
    }
}