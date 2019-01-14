class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i < s1.length(); i++) {
            dp[i + 1][0] = dp[i][0] + s1.codePointAt(i);
        }
        for (int i = 0; i < s2.length(); i++) {
            dp[0][i + 1] = dp[0][i] + s2.codePointAt(i);
        }
        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1.charAt(i);
            for (int j = 0; j < s2.length(); j++) {
                char c2 = s2.charAt(j);
                if (c1 == c2) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = Math.min(dp[i][j + 1] + s1.codePointAt(i), dp[i + 1][j] + s2.codePointAt(j));
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
}