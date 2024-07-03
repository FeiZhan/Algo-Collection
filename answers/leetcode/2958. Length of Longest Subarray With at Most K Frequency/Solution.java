class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int left = 0;
        int result = 0;
        Map<Integer, Integer> numberMap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            numberMap.put(number, numberMap.getOrDefault(number, 0) + 1);
            while (left <= i && numberMap.get(number) > k) {
                int leftNumber = nums[left];
                numberMap.put(leftNumber, numberMap.get(leftNumber) - 1);
                left++;
            }
            result = Math.max(result, i - left + 1);
        }

        return result;
    }
}