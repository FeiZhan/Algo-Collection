class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Set<Integer> duplicates = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            int num = Math.abs(nums[i]);
            if (nums[num - 1] > 0) {
                nums[num - 1] *= -1;
            } else {
                duplicates.add(num);
            }
        }
        return new ArrayList<Integer>(duplicates);
    }
}