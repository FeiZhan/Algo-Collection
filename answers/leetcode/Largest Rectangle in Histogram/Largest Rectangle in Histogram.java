class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int largest = 0;
        for (int i = 0; i <= heights.length; i++) {
            if (i < heights.length && (stack.isEmpty() || heights[i] >= heights[stack.peek()])) {
                stack.push(i);
            } else if (!stack.isEmpty()) {
                int top = stack.pop();
                largest = Math.max(largest, heights[top] * (stack.isEmpty() ? i : i - 1 - stack.peek()));
                i--;
            }
        }
        return largest;
    }
}