class Solution {
    public long getDescentPeriods(int[] prices) {
        int left = 0;
        long result = 1l;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i - 1] != prices[i] + 1) {
                left = i;
            }
            result += i - left + 1;
        }

        return result;
    }
}