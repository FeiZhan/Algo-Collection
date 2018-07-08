class Solution {
    public int longestPalindromeSubseq(String s) {
        int[][] dp = new int[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; i + j < s.length(); j++) {
                if (i == 0) {
                    dp[j][i + j] = 1;
                } else if (i == 1) {
                    dp[j][i + j] = (s.charAt(j) == s.charAt(i + j) ? 2 : 1);
                } else {
                    dp[j][i + j] = Math.max(dp[j + 1][i + j - 1] + (s.charAt(j) == s.charAt(i + j) ? 2 : 0),
                        Math.max(dp[j][i + j - 1], dp[j + 1][i + j]));
                }
            }
        }
        return dp[0][s.length() - 1];
    }
}