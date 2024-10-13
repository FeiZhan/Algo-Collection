class Solution {
    public long maximumTotalSum(int[] maximumHeight) {
        Arrays.sort(maximumHeight);
        int height = Integer.MAX_VALUE;
        long result = 0l;
        for (int i = maximumHeight.length - 1; i >= 0; i--) {
            height = Math.min(height - 1, maximumHeight[i]);
            if (height <= 0) {
                return -1l;
            }
            result += height;
        }

        return result;
    }
}