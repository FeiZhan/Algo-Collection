class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String token : tokens) {
            int number0;
            int number1;
            switch (token) {
                case "+":
                    number0 = stack.pop();
                    number1 = stack.pop();
                    stack.push(number0 + number1);
                    break;
                case "-":
                    number0 = stack.pop();
                    number1 = stack.pop();
                    stack.push(number1 - number0);
                    break;
                case "*":
                    number0 = stack.pop();
                    number1 = stack.pop();
                    stack.push(number0 * number1);
                    break;
                case "/":
                    number0 = stack.pop();
                    number1 = stack.pop();
                    stack.push(number1 / number0);
                    break;
                default:
                    stack.push(Integer.parseInt(token));
                    break;
            }
        }
        return stack.isEmpty() ? 0 : stack.pop();
    }
}
//Runtime: 4 ms, faster than 93.38% of Java online submissions for Evaluate Reverse Polish Notation.
//Memory Usage: 38.8 MB, less than 59.87% of Java online submissions for Evaluate Reverse Polish Notation.
