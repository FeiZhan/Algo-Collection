class Solution {
    public int nthUglyNumber(int n) {
        int[] ugly = new int[n];
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        int factor2 = 1;
        int factor3 = 1;
        int factor5 = 1;
        for (int i = 0; i < n; i++) {
            ugly[i] = Math.min(Math.min(factor2, factor3), factor5);
            if (factor2 == ugly[i]) {
                factor2 = 2 * ugly[index2];
                index2++;
            }
            if (factor3 == ugly[i]) {
                factor3 = 3 * ugly[index3];
                index3++;
            }
            if (factor5 == ugly[i]) {
                factor5 = 5 * ugly[index5];
                index5++;
            }
        }
        return ugly[n - 1];
    }
}