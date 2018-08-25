class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        dp[0][0] = true;
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                switch (p.charAt(j - 1)) {
                    case '?':
                        dp[i][j] = i > 0 ? dp[i - 1][j - 1] : false;
                        break;
                    case '*':
                        dp[i][j] = dp[i][j - 1] || (i > 0 ? dp[i - 1][j] : false);
                        break;
                    default:
                        dp[i][j] = i > 0 ? dp[i - 1][j - 1] && s.charAt(i - 1) == p.charAt(j - 1) : false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
}