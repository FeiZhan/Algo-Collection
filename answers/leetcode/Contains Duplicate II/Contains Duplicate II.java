class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> near = new HashSet<Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (near.contains(nums[i])) {
                return true;
            } else {
                near.add(nums[i]);
                if (near.size() > k) {
                    near.remove(nums[i - k]);
                }
            }
        }
        return false;
    }
}