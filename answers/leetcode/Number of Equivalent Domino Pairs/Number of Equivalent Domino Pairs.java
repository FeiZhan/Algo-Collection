class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int[] domino : dominoes) {
            int number = domino[0] < domino[1] ? domino[0] * 10000 + domino[1] : domino[1] * 10000 + domino[0];
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }
        int pairs = 0;
        for (int count : counts.values()) {
            pairs += (count - 1) * count / 2;
        }
        return pairs;
    }
}