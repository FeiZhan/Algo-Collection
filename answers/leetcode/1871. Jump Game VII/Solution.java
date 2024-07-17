class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int length = s.length();
        if (s.charAt(0) != '0' || s.charAt(length - 1) != '0') {
            return false;
        }

        boolean[] dp = new boolean[length];
        dp[0] = true;
        int left = 0;
        int right = 0;
        for (int i = 0; i < length; i++) {
            if (s.charAt(i) != '0' || !dp[i]) {
                continue;
            }
            left = Math.max(right + 1, i + minJump);
            right = Math.min(i + maxJump, length - 1);
            for (int j = left; j <= right; j++) {
                if (s.charAt(j) == '0') {
                    dp[j] = true;
                }
            }
            if (dp[length - 1]) {
                return true;
            }
        }

        return dp[length - 1];
    }
}