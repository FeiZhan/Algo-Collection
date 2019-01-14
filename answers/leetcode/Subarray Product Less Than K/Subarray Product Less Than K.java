class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int count = 0;
        int left = 0;
        int product = 1;
        for (int i = 0; i < nums.length; i++) {
            product *= nums[i];
            while (left < nums.length && product >= k) {
                product /= nums[left];
                left++;
            }
            if (left >= nums.length) {
                break;
            }
            count += i - left + 1;
            //System.out.println(left + " " + i + ": " + product + " " + count);
        }
        return count;
    }
}