class Solution {
    public void rotate(int[] nums, int k) {
        int[] original = nums.clone();
        for (int i = 0; i < original.length; i++) {
            nums[(i + k) % original.length] = original[i];
        }
    }
}