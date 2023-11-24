class Solution {
    public int minStoneSum(int[] piles, int k) {
        PriorityQueue<Integer> stones = new PriorityQueue<>(Collections.reverseOrder());
        for (int pile : piles) {
            stones.add(pile);
        }

        for (int i = 0; i < k; i++) {
            int stone = stones.poll();
            stone = (int) Math.ceil((double) stone / 2.0);
            stones.add(stone);
        }

        int result = 0;
        for (int stone : stones) {
            result += stone;
        }

        return result;
    }
}