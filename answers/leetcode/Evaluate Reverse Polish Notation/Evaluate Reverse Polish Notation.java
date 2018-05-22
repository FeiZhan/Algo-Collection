class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String token : tokens) {
            if (token.length() > 0 && Character.isDigit(token.charAt(token.length() - 1))) {
                stack.push(Integer.parseInt(token));
            } else if (token.length() > 0) {
                int num0 = stack.pop();
                int num1 = stack.pop();
                switch (token.charAt(0)) {
                    case '+':
                        num1 += num0;
                        break;
                    case '-':
                        num1 -= num0;
                        break;
                    case '*':
                        num1 *= num0;
                        break;
                    case '/':
                        num1 /= num0;
                        break;
                }
                stack.push(num1);
            }
        }
        return stack.pop();
    }
}