class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int result = 0;
        for (int number : left) {
            result = Math.max(result, number);
        }
        for (int number : right) {
            result = Math.max(result, n - number);
        }

        return result;
    }
}