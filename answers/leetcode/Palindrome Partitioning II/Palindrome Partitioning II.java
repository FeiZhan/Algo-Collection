class Solution {
    public int minCut(String s) {
        int length = s.length();
        boolean[][] dp = new boolean[length][length];
        for (int i = 0; i < length; i++) {
            for (int j = 0; i + j < length; j++) {
                boolean flag = false;
                if (i == 0) {
                    flag = true;
                } else if (i == 1) {
                    flag = s.charAt(j) == s.charAt(i + j);
                } else {
                    flag = dp[j + 1][i + j - 1] && s.charAt(j) == s.charAt(i + j);
                }
                dp[j][i + j] = flag;
            }
        }
        int[] cut = new int[length + 1];
        for (int i = 1; i <= length; i++) {
            cut[i] = length + 1;
        }
        for (int i = 0; i < length; i++) {
            for (int j = i; j < length; j++) {
                if (dp[i][j]) {
                    cut[j + 1] = Math.min(cut[j + 1], cut[i] + 1);
                }
            }
        }
        return cut[length] - 1;
    }
}