class Solution {
    public int minIncrements(int n, int[] cost) {
        int square = 1;
        int sum = 0;

        while (square < cost.length) {
            int max = 0;
            for (int i = square - 1; i < square * 2 - 1 && i < cost.length; i++) {
                max = Math.max(max, cost[i]);
            }
            for (int i = square - 1; i < square * 2 - 1 && i < cost.length; i++) {
                sum += max - cost[i];
            }
            square *= 2;
        }

        return sum;
    }
}