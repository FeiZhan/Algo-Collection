class Solution {
    public int maximumProduct(int[] nums) {
        int[] max = new int[5];
        max[2] = Integer.MIN_VALUE;
        max[3] = Integer.MIN_VALUE;
        max[4] = Integer.MIN_VALUE;
        for (int num : nums) {
            if (num < 0) {
                if (num < max[0]) {
                    max[1] = max[0];
                    max[0] = num;
                } else if (num < max[1]) {
                    max[1] = num;
                }
            }
            if (num > max[4]) {
                max[2] = max[3];
                max[3] = max[4];
                max[4] = num;
            } else if (num > max[3]) {
                max[2] = max[3];
                max[3] = num;
            } else if (num > max[2]) {
                max[2] = num;
            }
        }
        int result = max[2] * max[3] * max[4];
        return max[0] < 0 && max[1] < 0 ? Math.max(result, max[0] * max[1] * max[4]) : result;
    }
}