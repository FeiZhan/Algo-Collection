class Solution {
    public int minimumCost(int[] cost) {
        int result = 0;
        Arrays.sort(cost);

        for (int i = cost.length - 1; i >= 0; i-= 3) {
            result += cost[i];
            if (i >= 1) {
                result += cost[i - 1];
            }
        }

        return result;
    }
}
//Runtime: 3 ms, faster than 66.69% of Java online submissions for Minimum Cost of Buying Candies With Discount.
//Memory Usage: 39.3 MB, less than 81.66% of Java online submissions for Minimum Cost of Buying Candies With Discount.
