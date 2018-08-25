class Solution {
    public int calculate(String s) {
        int result = 0;
        int number = 0;
        int sign = 1;
        Stack<Integer> signStack = new Stack<>();
        signStack.push(1);
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                number = number * 10 + Character.getNumericValue(c);
            } else {
                result += number * sign;
                number = 0;
            }
            switch (c) {
                case '+':
                    sign *= signStack.pop();
                    signStack.push(1);
                    break;
                case '-':
                    sign *= signStack.pop() * -1;
                    signStack.push(-1);
                    break;
                case '(':
                    signStack.push(1);
                    break;
                case ')':
                    sign *= signStack.pop();
                    break;
                case ' ':
                default:
                    break;
            }
            //System.out.println(c + ": " + number + " " + sign + " " + signStack.peek() + " " + result);
        }
        return result + number * sign;
    }
}