class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int[][] dp = new int[dungeon.length][dungeon[0].length];
        for (int i = dungeon.length - 1; i >= 0; i--) {
            for (int j = dungeon[i].length - 1; j >= 0; j--) {
                int minHp = Integer.MAX_VALUE;
                if (i + 1 < dungeon.length) {
                    minHp = Math.min(minHp, dp[i + 1][j]);
                }
                if (j + 1 < dungeon[i].length) {
                    minHp = Math.min(minHp, dp[i][j + 1]);
                }
                if (minHp == Integer.MAX_VALUE) {
                    minHp = 1;
                }
                minHp -= dungeon[i][j];
                dp[i][j] = minHp > 0 ? minHp : 1;
            }
        }
        return dp[0][0];
    }
}