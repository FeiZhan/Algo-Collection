class Solution {
    public int getMaximumConsecutive(int[] coins) {
        Arrays.sort(coins);
        if (coins.length < 1 || coins[0] != 1) {
            return 1;
        }

        int result = 0;
        for (int coin : coins) {
            if (coin > result + 1) {
                return result + 1;
            }

            result = Math.max(coin, result + coin);
        }

        return result + 1;
    }
}