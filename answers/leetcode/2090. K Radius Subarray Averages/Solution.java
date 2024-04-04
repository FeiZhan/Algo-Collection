class Solution {
    public int[] getAverages(int[] nums, int k) {
        int left = 0;
        int length = k + k + 1;
        long sum = 0l;
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            while (i - left + 1 > length) {
                sum -= nums[left];
                left++;
            }
            result[i] = -1;
            if (i - left + 1 == length) {
                result[i - k] = (int) (sum / length);
            }
        }

        return result;
    }
}