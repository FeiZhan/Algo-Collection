class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.length; i++) {
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (Math.abs(sum - target) < Math.abs(result - target)) {
                    result = sum;
                }
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    break;
                }
            }
        }

        return result;
    }
}
//Runtime: 14 ms, faster than 17.20% of Java online submissions for 3Sum Closest.
//Memory Usage: 39.8 MB, less than 21.23% of Java online submissions for 3Sum Closest.
