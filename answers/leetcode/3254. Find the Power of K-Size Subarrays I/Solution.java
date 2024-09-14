class Solution {
    public int[] resultsArray(int[] nums, int k) {
        boolean flag = false;
        int length = nums.length;
        int[] result = new int[length - k + 1];

        for (int i = 0; i + k - 1 < length; i++) {
            if (flag) {
                if (k == 1 || nums[i + k - 2] + 1 == nums[i + k - 1]) {
                    result[i] = nums[i + k - 1];
                } else {
                    result[i] = -1;
                    flag = false;
                }
            } else {
                flag = true;
                for (int j = 1; j < k; j++) {
                    if (nums[i + j - 1] + 1 != nums[i + j]) {
                        flag = false;
                        break;
                    }
                }
                result[i] = flag ? nums[i + k - 1] : -1;
            }
        }

        return result;
    }
}