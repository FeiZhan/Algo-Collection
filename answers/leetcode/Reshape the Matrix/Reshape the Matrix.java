class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if (null == nums || nums.length * nums[0].length != r * c) {
            return nums;
        }
        int[][] reshaped = new int[r][c];
        for (int i = 0, k = 0, m = 0; i < nums.length; i++) {
            for (int j = 0; j < nums[i].length; j++, m++) {
                while (m >= c) {
                    m -= c;
                    k++;
                }
                reshaped[k][m] = nums[i][j];
            }
        }
        return reshaped;
    }
}