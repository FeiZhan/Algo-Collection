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
    
    public void update(int i, int val) {
        int diff = val - this.sums[i] + (i > 0 ? this.sums[i - 1] : 0);
        for (int j = i; j < this.sums.length; j++) {
            this.sums[j] += diff;
        }
    }
    
    public int sumRange(int i, int j) {
        return this.sums[j] - (i > 0 ? this.sums[i - 1] : 0);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */