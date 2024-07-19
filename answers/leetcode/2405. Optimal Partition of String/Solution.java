class Solution {
    public int partitionString(String s) {
        int result = 0;
        Set<Character> charSet = new HashSet<>();
        for (char c : s.toCharArray()) {
            if (charSet.contains(c)) {
                result++;
                charSet.clear();
            }
            charSet.add(c);
        }

        return result + (charSet.isEmpty() ? 0 : 1);
    }
}