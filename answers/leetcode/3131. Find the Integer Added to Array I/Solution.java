class Solution {
    public int addedInteger(int[] nums1, int[] nums2) {
        int min1 = Integer.MAX_VALUE;
        for (int number : nums1) {
            min1 = Math.min(min1, number);
        }
        int min2 = Integer.MAX_VALUE;
        for (int number : nums2) {
            min2 = Math.min(min2, number);
        }

        return min2 - min1;
    }
}