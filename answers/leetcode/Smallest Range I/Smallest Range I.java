class Solution {
    public int smallestRangeI(int[] A, int K) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int number : A) {
            max = Math.max(max, number);
            min = Math.min(min, number);
        }
        return Math.max(0, max - min - K - K);
    }
}