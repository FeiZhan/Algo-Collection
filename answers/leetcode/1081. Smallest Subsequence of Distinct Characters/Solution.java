class Solution {
    public String smallestSubsequence(String s) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            charMap.put(c, i);
        }

        Set<Character> charSet = new HashSet<>();
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (charSet.contains(c)) {
                continue;
            }
            while (!stack.isEmpty()) {
                char previous = stack.peek();
                if (previous <= c || i >= charMap.get(previous)) {
                    break;
                }
                stack.pop();
                charSet.remove(previous);
            }
            stack.add(c);
            charSet.add(c);
        }

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.insert(0, stack.pop());
        }

        return sb.toString();
    }
}