class Solution {
    public boolean isValid(String s) {
        if (null == s) {
            return true;
        }
        
        Map<Character, Character> Parentheses = new HashMap<Character, Character>();
        Parentheses.put('(', ')');
        Parentheses.put('[', ']');
        Parentheses.put('{', '}');
        Stack<Character> stack = new Stack<Character>();
        for (char c : s.toCharArray()) {
            if (Parentheses.containsKey(c)) {
                stack.push(Parentheses.get(c));
            } else if (! stack.empty() && stack.peek() == c) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
}