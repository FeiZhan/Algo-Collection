class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int[] dp = new int[A.length];
        int sum = 0;
        for (int i = 2; i < A.length; i++) {
            if (A[i - 2] - A[i - 1] == A[i - 1] - A[i]) {
                dp[i] = dp[i - 1] + 1;
            }
            sum += dp[i];
        }
        return sum;
    }
}