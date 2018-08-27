class Solution {
    
    private int[] dp = new int[1000000];
    
    public int numTrees(int n) {
        if (this.dp[n] == 0) {
            if (n <= 1) {
                this.dp[n] = 1;
            } else {
                int sum = 0;
                for (int i = 1; i <= n; i++) {
                    sum += this.numTrees(i - 1) * this.numTrees(n - i);
                }
                this.dp[n] = sum;
            }
        }
        return this.dp[n];
    }
}