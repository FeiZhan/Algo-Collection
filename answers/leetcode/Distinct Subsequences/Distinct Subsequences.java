class Solution {
    public int numDistinct(String s, String t) {
        int[][] dp = new int[s.length() + 1][t.length() + 1];
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= t.length(); j++) {
                int count = 0;
                if (i == 0 && j == 0) {
                    count++;
                } else if (i > 0) {
                    if (j > 0 && s.charAt(i - 1) == t.charAt(j - 1)) {
                        count += dp[i - 1][j - 1];
                    }
                    count += dp[i - 1][j];
                }
                dp[i][j] = count;
            }
        }
        return dp[s.length()][t.length()];
    }
}