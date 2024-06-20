class Solution {
    public int minimumSubstringsInPartition(String s) {
        int length = s.length();
        boolean[][] balanced = new boolean[length][length];
        for (int i = 0; i < length; i++) {
            Map<Character, Integer> counts = new HashMap<>();
            for (int j = i; j < length; j++) {
                char c = s.charAt(j);
                int count = counts.getOrDefault(c, 0) + 1;
                counts.put(c, count);
                balanced[i][j] = true;
                for (int temp : counts.values()) {
                    if (temp != count) {
                        balanced[i][j] = false;
                        break;
                    }
                }
            }
        }

        int[] dp = new int[length];
        for (int i = 0; i < length; i++) {
            dp[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < length; i++) {
            for (int j = i; j < length; j++) {
                if (!balanced[i][j]) {
                    continue;
                }
                dp[j] = Math.min(dp[j], (i > 0 && dp[i - 1] != Integer.MAX_VALUE ? dp[i - 1] : 0) + 1);
            }
        }

        return dp[length - 1];
    }
}