class Solution {
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        int result = 0;
        for (int i = 0; i + pattern.length < nums.length; i++) {
            boolean flag = true;
            for (int j = 0; j < pattern.length; j++) {
                switch (pattern[j]) {
                    case 1:
                        flag = nums[i + j] < nums[i + j + 1];
                        break;
                    case 0:
                        flag = nums[i + j] == nums[i + j + 1];
                        break;
                    case -1:
                        flag = nums[i + j] > nums[i + j + 1];
                        break;
                }
                if (!flag) {
                    break;
                }
            }
            result += flag ? 1 : 0;
        }

        return result;
    }
}