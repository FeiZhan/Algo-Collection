class Solution {
    public int arrayNesting(int[] nums) {
        int[] length = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            this.dfs(i, length, nums);
        }
        int maxLength = 0;
        for (int num : length) {
            maxLength = Math.max(maxLength, num);
        }
        return maxLength;
    }

    private int dfs(int index, int[] length, int[] nums) {
        if (length[index] == 0) {
            length[index] = Integer.MAX_VALUE;
            int nextLength = this.dfs(nums[index], length, nums);
            length[index] = (nextLength != Integer.MAX_VALUE ? nextLength : 0) + 1;
        }
        return length[index];
    }
}