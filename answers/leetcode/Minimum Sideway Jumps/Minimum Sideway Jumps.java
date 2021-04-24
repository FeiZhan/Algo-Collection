class Solution {

    private static final int OBSTACLE = Integer.MAX_VALUE / 2;

    public int minSideJumps(int[] obstacles) {
        int[] dp = new int[3];
        dp[0] = obstacles[0] == 1 ? OBSTACLE : 1;
        dp[2] = obstacles[0] == 3 ? OBSTACLE : 1;
        for (int i = 1; i < obstacles.length; i++) {
            int[] next = new int[3];
            switch (obstacles[i]) {
                case 0:
                    next[0] = Math.min(dp[0], Math.min(dp[1] + 1, dp[2] + 1));
                    next[1] = Math.min(dp[1], Math.min(dp[0] + 1, dp[2] + 1));
                    next[2] = Math.min(dp[2], Math.min(dp[0] + 1, dp[1] + 1));
                    break;
                case 1:
                    next[0] = OBSTACLE;
                    next[1] = Math.min(dp[1], dp[2] + 1);
                    next[2] = Math.min(dp[2],  dp[1] + 1);
                    break;
                case 2:
                    next[0] = Math.min(dp[0], dp[2] + 1);
                    next[1] = OBSTACLE;
                    next[2] = Math.min(dp[2], dp[0] + 1);
                    break;
                case 3:
                    next[0] = Math.min(dp[0], dp[1] + 1);
                    next[1] = Math.min(dp[1], dp[0] + 1);
                    next[2] = OBSTACLE;
                    break;
            }
            for (int j = 0; j < 3; j++) {
                dp[j] = next[j];
                //System.out.println(i + " " + j + " " + dp[j]);
            }
        }
        return Math.min(dp[0], Math.min(dp[1], dp[2]));
    }
}