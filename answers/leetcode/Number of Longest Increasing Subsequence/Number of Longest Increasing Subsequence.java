class Solution {
    public int findNumberOfLIS(int[] nums) {
        int[] counts = new int[nums.length];
        int[] lengths = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            counts[i] = 1;
            lengths[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lengths[i] < lengths[j] + 1) {
                        lengths[i] =  lengths[j] + 1;
                        counts[i] = counts[j];
                    } else if (lengths[i] == lengths[j] + 1) {
                        counts[i] += counts[j];
                    }
                }
            }
        }
        int maxCount = 0;
        int maxLength = 0;
        for (int i = 0; i < lengths.length; i++) {
            if (lengths[i] > maxLength) {
                maxLength = lengths[i];
                maxCount = counts[i];
            } else if (lengths[i] == maxLength) {
                maxCount += counts[i];
            }
            System.out.println(i + ": " + lengths[i] + " " + counts[i] + ", " + maxLength + " " + maxCount);
        }
        return maxCount;
    }
}