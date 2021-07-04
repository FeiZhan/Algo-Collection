class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int left = 0;
        int sum = 0;
        int result = 0;
        Set<Integer> numbers = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            if (numbers.contains(nums[i])) {
                for (; left <= i; left++) {
                    sum -= nums[left];
                    numbers.remove(nums[left]);
                    if (nums[left] == nums[i]) {
                        left++;
                        break;
                    }
                }
            }

            sum += nums[i];
            numbers.add(nums[i]);
            result = Math.max(result, sum);
        }

        return result;
    }
}