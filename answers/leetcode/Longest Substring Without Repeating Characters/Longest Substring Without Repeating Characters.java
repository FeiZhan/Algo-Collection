class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0;
        Set<Character> charSet = new HashSet<Character>();
        for (int i = 0, j = 0; j < s.length(); j++) {
            char c = s.charAt(j);
            if (charSet.contains(c)) {
                while (s.charAt(i) != c) {
                    charSet.remove(s.charAt(i));
                    i++;
                }
                i++;
            } else {
                charSet.add(c);
                maxLength = Math.max(maxLength, charSet.size());
            }
        }
        return maxLength;
    }
}