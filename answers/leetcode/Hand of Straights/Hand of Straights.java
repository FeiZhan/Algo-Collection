import java.util.SortedMap;

class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        SortedMap<Integer, Integer> hands = new TreeMap<>();
        for (int number : hand) {
            hands.put(number, hands.getOrDefault(number, 0) + 1);
        }
        while (hands.size() > 0) {
            int start = hands.firstKey();
            for (int i = 0; i < W; i++) {
                int current = start + i;
                if (!hands.containsKey(current)) {
                    return false;
                }
                hands.put(current, hands.get(current) - 1);
                if (hands.get(current) == 0) {
                    hands.remove(current);
                }
            }
        }
        return true;
    }
}