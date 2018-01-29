class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (null == nums || nums.length == 0) {
            return false;
        }
        Set<Integer> numSet = new HashSet<Integer>();
        for (int num : nums) {
            if (numSet.contains(num)) {
                return true;
            } else {
                numSet.add(num);
            }
        }
        return false;
    }
}