class Solution {
    public int numSubseq(int[] nums, int target) {
        int MOD = (int) 1e9 + 7;
        int[] POWS = new int[nums.length];
        POWS[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            POWS[i] = POWS[i - 1] * 2 % MOD;
        }

        Arrays.sort(nums);
        int left = 0;
        int right = nums.length - 1;
        int result = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + POWS[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
}