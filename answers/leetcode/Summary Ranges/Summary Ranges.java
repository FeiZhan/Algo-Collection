class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ranges = new ArrayList<>();
        boolean isRange = false;
        for (int i = 0; i <= nums.length; i++) {
            if (i > 0 && i < nums.length && nums[i] - nums[i - 1] == 1) {
                isRange = true;
            } else if (isRange) {
                ranges.set(ranges.size() - 1, ranges.get(ranges.size() - 1) + "->" + Integer.toString(nums[i - 1]));
                if (i < nums.length) {
                    ranges.add(Integer.toString(nums[i]));
                }
                isRange = false;
            } else {
                if (i < nums.length) {
                    ranges.add(Integer.toString(nums[i]));
                }
            }
        }
        return ranges;
    }
}