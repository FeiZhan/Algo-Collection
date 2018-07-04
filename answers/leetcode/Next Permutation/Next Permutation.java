class Solution {
    public void nextPermutation(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return;
        }
        
        int left = nums.length - 2;
        while (left >= 0 && nums[left] >= nums[left + 1]) {
            left--;
        }
        if (left < 0) {
            for (int i = 0; i * 2 < nums.length; i++) {
                int temp = nums[i];
                nums[i] = nums[nums.length - 1 - i];
                nums[nums.length - 1 - i] = temp;
            }
            return;
        }
        int right = left + 1;
        while (right < nums.length && nums[left] < nums[right]) {
            right++;
        }
        right--;
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        Arrays.sort(nums, left + 1, nums.length);
    }
}