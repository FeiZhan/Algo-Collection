class Solution {
    public String reverseParentheses(String s) {
        Map<Integer, Integer> parentheses = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                stack.push(i);
            } else if (c == ')') {
                int left = stack.pop();
                parentheses.put(left, i);
                parentheses.put(i, left);
            }
        }
        boolean toRight = true;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i >= 0 && i < s.length(); i += (toRight ? 1 : -1)) {
            char c = s.charAt(i);
            System.out.println(i + " " + c);
            if (c == '(' || c == ')') {
                i = parentheses.get(i);
                toRight = !toRight;
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}