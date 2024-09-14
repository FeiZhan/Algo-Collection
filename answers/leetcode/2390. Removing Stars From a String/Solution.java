class Solution {
    public String removeStars(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '*' && !stack.isEmpty()) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (char c : stack) {
            sb.append(c);
        }

        return sb.toString();
    }
}