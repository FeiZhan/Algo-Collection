class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[] {0, 0};
        Map<Integer, Integer> numMap = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            int diff = target - nums[i];
            if (numMap.containsKey(diff)) {
                result[0] = numMap.get(diff);
                result[1] = i;
                return result;
            }
            numMap.put(nums[i], i);
        }
        return result;
    }
}
