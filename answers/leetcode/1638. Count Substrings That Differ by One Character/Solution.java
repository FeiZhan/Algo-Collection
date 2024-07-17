class Solution {
    public int countSubstrings(String s, String t) {
        int sLength = s.length();
        int tLength = t.length();
        int[][] leftDp = new int[sLength][tLength];
        for (int i = 0; i < sLength; i++) {
            for (int j = 0; j < tLength; j++) {
                if (s.charAt(i) == t.charAt(j)) {
                    leftDp[i][j] = 1 + (i > 0 && j > 0 ? leftDp[i - 1][j - 1] : 0);
                }
            }
        }
        int[][] rightDp = new int[sLength][tLength];
        for (int i = sLength - 1; i >= 0; i--) {
            for (int j = tLength - 1; j >= 0; j--) {
                if (s.charAt(i) == t.charAt(j)) {
                    rightDp[i][j] = 1 + (i + 1 < sLength && j + 1 < tLength ? rightDp[i + 1][j + 1] : 0);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < sLength; i++) {
            for (int j = 0; j < tLength; j++) {
                if (s.charAt(i) != t.charAt(j)) {
                    int left = (i > 0 && j > 0 ? leftDp[i - 1][j - 1] : 0) + 1;
                    int right = (i + 1 < sLength && j + 1 < tLength ? rightDp[i + 1][j + 1] : 0) + 1;
                    result += left * right;
                }
            }
        }

        return result;
    }
}