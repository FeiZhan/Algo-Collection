class Solution {
    public int maxProduct(int[] nums) {
        int max = 0;
        int max1 = 0;
        for (int number : nums) {
            if (number > max) {
                max1 = max;
                max = number;
            } else if (number > max1) {
                max1 = number;
            }
        }
        return (max - 1) * (max1 - 1);
    }
}