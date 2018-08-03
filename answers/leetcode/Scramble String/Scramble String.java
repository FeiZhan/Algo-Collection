class Solution {
    public boolean isScramble(String s1, String s2) {
        int length = s1.length();
        boolean[][][] scramble = new boolean[length][length][length];
        for (int i = 0; i < length; i++) {
            for (int j = 0; i + j < length; j++) {
                for (int k = 0; i + k < length; k++) {
                    if (i == 0) {
                        scramble[i][j][k] = s1.charAt(j) == s2.charAt(k);
                    } else {
                        for (int m = 0; m < i; m++) {
                            if ((scramble[m][j][k] && scramble[i - m - 1][j + m + 1][k + m + 1])
                                || (scramble[m][j][k + i - m] && scramble[i - m - 1][j + m + 1][k])) {
                                scramble[i][j][k] = true;
                                break;
                            }
                        }
                    }
                    //System.out.println(i + " " + j + " " + k + ": " + s1.substring(j, j + i + 1) + " " + s2.substring(k, k + i + 1) + " " + scramble[i][j][k]);
                }
            }
        }
        return scramble[length - 1][0][0];
    }
}