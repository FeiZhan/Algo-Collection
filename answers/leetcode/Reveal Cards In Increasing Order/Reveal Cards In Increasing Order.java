import java.util.SortedSet;

class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        SortedSet<Integer> cards = new TreeSet<>();
        for (int card : deck) {
            cards.add(card);
        }
        boolean flag = true;
        int[] result = new int[deck.length];
        while (!cards.isEmpty()) {
            for (int i = 0; i < result.length; i++) {
                if (cards.isEmpty()) {
                    break;
                }
                if (result[i] == 0) {
                    if (flag) {
                        result[i] = cards.first();
                        cards.remove(result[i]);
                    }
                    flag = !flag;
                }
            }
        }
        return result;
    }
}