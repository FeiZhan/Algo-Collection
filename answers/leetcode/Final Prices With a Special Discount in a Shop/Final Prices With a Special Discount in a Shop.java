class Solution {
    public int[] finalPrices(int[] prices) {
        int[] result = new int[prices.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < prices.length; i++) {
            int current = prices[i];
            while (!stack.isEmpty()) {
                int index = stack.peek();
                if (current <= prices[index]) {
                    result[index] = prices[index] - current;
                    stack.pop();
                } else {
                    break;
                }
            }
            stack.push(i);
        }
        while (!stack.isEmpty()) {
            int index = stack.pop();
            result[index] = prices[index];
        }
        return result;
    }
}