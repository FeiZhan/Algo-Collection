class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int[] result = new int[2];
        for (int i = 0; i < mat.length; i++) {
            int count = 0;
            for (int cell : mat[i]) {
                count += cell;
            }
            if (count > result[1]) {
                result[0] = i;
                result[1] = count;
            }
        }

        return result;
    }
}