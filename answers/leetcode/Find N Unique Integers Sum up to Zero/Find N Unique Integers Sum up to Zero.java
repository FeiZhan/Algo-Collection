class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        for (int i = 1; i * 2 < n; i++) {
            result[i * 2 - 2] = -i;
            result[i * 2 - 1] = i;
        }
        if (n % 2 == 1) {
            result[n - 1] = 0;
        }
        return result;
    }
}