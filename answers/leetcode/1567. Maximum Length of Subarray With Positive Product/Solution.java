class Solution {
    public int getMaxLen(int[] nums) {
        int positiveLeft = -1;
        int negativeLeft = -1;
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                if (positiveLeft == -1) {
                    positiveLeft = i;
                }
            } else if (nums[i] < 0) {
                int temp = negativeLeft;
                negativeLeft = positiveLeft;
                positiveLeft = temp;
                if (negativeLeft == -1) {
                    negativeLeft = i;
                }
            } else {
                positiveLeft = -1;
                negativeLeft = -1;
            }
            if (positiveLeft >= 0) {
                result = Math.max(result, i - positiveLeft + 1);
            }
        }

        return result;
    }
}