class Solution {
    
    private int[] nums;
    private Random random;

    public Solution(int[] nums) {
        this.nums = nums.clone();
        this.random = new Random();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return this.nums.clone();
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        int[] shuffled = this.nums.clone();
        for (int i = 0; i < shuffled.length; i++) {
            int index = this.random.nextInt(shuffled.length - i) + i;
            int temp = shuffled[i];
            shuffled[i] = shuffled[index];
            shuffled[index] = temp;
        }
        return shuffled;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */