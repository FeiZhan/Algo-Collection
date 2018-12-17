class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int[] greater = new int[nums.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
                int index = stack.pop();
                greater[index] = nums[i];
            }
            stack.push(i);
        }
        if (!stack.isEmpty()) {
            for (int i = 0; i < nums.length; i++) {
                while (!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
                    int index = stack.pop();
                    greater[index] = nums[i];
                }
            }
        }
        if (!stack.isEmpty()) {
            while (!stack.isEmpty()) {
                greater[stack.pop()] = -1;
            }
        }
        return greater;
    }
}