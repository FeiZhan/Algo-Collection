class Solution {
    public boolean increasingTriplet(int[] nums) {
        int min0 = Integer.MAX_VALUE;
        int min1 = Integer.MAX_VALUE;
        for (int num : nums) {
            min0 = Math.min(min0, num);
            if (num > min0 && num < min1) {
                min1 = num;
            } else if (num > min1) {
                return true;
            }
        }
        return false;
    }
}