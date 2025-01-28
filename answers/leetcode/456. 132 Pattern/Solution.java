class Solution {
    public boolean find132pattern(int[] nums) {
        int[] mins = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            mins[i] = Math.min(nums[i], i > 0 ? mins[i - 1] : Integer.MAX_VALUE);
        }
        Stack<Integer> stack = new Stack<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] > mins[i]) {
                while (!stack.isEmpty() && stack.peek() <= mins[i]) {
                    stack.pop();
                }
                if (!stack.isEmpty() && stack.peek() < nums[i]) {
                    return true;
                }
                stack.push(nums[i]);
            }
        }

        return false;
    }
}