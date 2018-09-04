class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        boolean[] dp = new boolean[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i - 1]) {
                for (int j = i; j < s.length(); j++) {
                    if (!dp[j]) {
                        String substr = s.substring(i, j + 1);
                        if (wordSet.contains(substr)) {
                            dp[j] = true;
                        }
                    }
                }
            }
        }
        return dp[s.length() - 1];
    }
}