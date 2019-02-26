class Solution {
    public int calPoints(String[] ops) {
        int sum = 0;
        Stack<Integer> stack = new Stack<>();
        for (String op : ops) {
            switch (op.charAt(0)) {
                case '+':
                    if (stack.size() >= 2) {
                        int top = stack.pop();
                        int score = top + stack.peek();
                        stack.push(top);
                        stack.push(score);
                        sum += score;
                    }
                    break;
                case 'D':
                    if (!stack.empty()) {
                        int score = stack.peek() * 2;
                        stack.push(score);
                        sum += score;
                    }
                    break;
                case 'C':
                    if (!stack.empty()) {
                        int score = -stack.pop();
                        sum += score;
                    }
                    break;
                default:
                    int score = Integer.parseInt(op);
                    stack.push(score);
                    sum += score;
            }
        }
        return sum;
    }
}