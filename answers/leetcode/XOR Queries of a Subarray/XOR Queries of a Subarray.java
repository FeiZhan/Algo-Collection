class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] dp = new int[arr.length];
        dp[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            dp[i] = dp[i - 1] ^ arr[i];
        }
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            result[i] = (query[0] == 0 ? 0 : dp[query[0] - 1]) ^ dp[query[1]];
        }
        return result;
    }
}