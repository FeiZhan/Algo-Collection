class Solution {
    public long mostPoints(int[][] questions) {
        long result = 0l;
        long[] dp = new long[questions.length];
        for (int i = questions.length - 1; i >= 0; i--) {
            long dp1 = i + 1 < questions.length ? dp[i + 1] : 0l;
            long dpn = i + 1 + questions[i][1] < questions.length ? dp[i + 1 + questions[i][1]] : 0l;
            dp[i] = Math.max(dp1, dpn + questions[i][0]);
            result = Math.max(result, dp[i]);
        }

        return result;
    }
}