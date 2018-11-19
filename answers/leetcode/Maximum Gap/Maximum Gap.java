class Solution {
    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2) {
            return 0;
        }
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int num : nums) {
            max = Math.max(max, num);
            min = Math.min(min, num);
        }
        int gap = (int)Math.ceil((double)(max - min) / (nums.length - 1));
        if (gap == 0) {
            return 0;
        }
        int[] maxArray = new int[nums.length];
        Arrays.fill(maxArray, Integer.MIN_VALUE);
        int[] minArray = new int[nums.length];
        Arrays.fill(minArray, Integer.MAX_VALUE);
        for (int num : nums) {
            int index = (num - min) / gap;
            maxArray[index] = Math.max(maxArray[index], num);
            minArray[index] = Math.min(minArray[index], num);
        }
        int maxGap = Integer.MIN_VALUE;
        int previous = min;
        for (int i = 0; i < nums.length; i++) {
            if (minArray[i] == Integer.MAX_VALUE && maxArray[i] == Integer.MIN_VALUE) {
                continue;
            }
            maxGap = Math.max(maxGap, minArray[i] - previous);
            previous = maxArray[i];
        }
        return maxGap;
    }
}