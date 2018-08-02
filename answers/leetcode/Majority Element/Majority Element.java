class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> numCount = new HashMap<>();
        for (int num : nums) {
            int count = numCount.getOrDefault(num, 0) + 1;
            if (count > nums.length / 2) {
                return num;
            }
            numCount.put(num, count);
        }
        return -1;
    }
}