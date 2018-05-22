class Solution {
    public int maxProduct(int[] nums) {
        int maxProduct = Integer.MIN_VALUE;
        int[] maxValues = new int[nums.length];
        int[] minValues = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= 0) {
                maxValues[i] = Math.max(nums[i], nums[i] * (i > 0 ? maxValues[i - 1] : 1));
                minValues[i] = Math.min(nums[i], nums[i] * (i > 0 ? minValues[i - 1] : 1));
            } else {
                maxValues[i] = Math.max(nums[i], nums[i] * (i > 0 ? minValues[i - 1] : 1));
                minValues[i] = Math.min(nums[i], nums[i] * (i > 0 ? maxValues[i - 1] : 1));
            }
            maxProduct = Math.max(maxProduct, maxValues[i]);
        }
        return maxProduct;
    }
}