class Solution {
    public int trap(int[] height) {
        int trapped = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < height.length; i++) {
            while (stack.size() >= 2 && height[i] > height[stack.peek()]) {
                int current = stack.pop();
                int previous = stack.peek();
                int distance = i - previous - 1;
                int addedHeight = Math.min(height[i], height[previous]) - height[current];
                if (addedHeight > 0) {
                    trapped += distance * addedHeight;
                }
                //System.out.println(i + " " + previous + " " + current + ": " + distance + " " + addedHeight);
            }
            stack.push(i);
        }
        return trapped;
    }
}