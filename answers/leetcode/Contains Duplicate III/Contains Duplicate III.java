class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Long> numSet = new TreeSet<>();
        for (int i = 0; i < nums.length; i++) {
            Long floor = numSet.floor((long) (nums[i] + t));
            if (floor != null && nums[i] - floor <= t) {
                return true;
            }
            Long ceiling = numSet.ceiling((long) (nums[i] - t));
            if (ceiling != null && ceiling - nums[i] <= t) {
                return true;
            }
            numSet.add((long) nums[i]);
            if (i >= k) {
                numSet.remove((long) nums[i - k]);
            }
        }
        return false;
    }
}