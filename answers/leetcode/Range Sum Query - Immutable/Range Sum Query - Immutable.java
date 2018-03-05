class NumArray {

    private int[] sums;

    public NumArray(int[] nums) {
        this.sums = new int[nums.length];
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            this.sums[i] = sum;
        }
    }

    public int sumRange(int i, int j) {
        return this.sums[j] - (i > 0 ? this.sums[i - 1] : 0);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */