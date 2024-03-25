class Solution {
    public int maximumLengthSubstring(String s) {
        Set<Character> chars = new HashSet<>();
        for (char c : s.toCharArray()) {
            chars.add(c);
        }

        int left = 0;
        int maxLength = 0;
        Map<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            counts.put(c, counts.getOrDefault(c, 0) + 1);
            while (counts.get(c) > 2) {
                char leftChar = s.charAt(left);
                counts.put(leftChar, counts.get(leftChar) - 1);
                left++;
            }
            maxLength = Math.max(maxLength, i - left + 1);
        }

        return maxLength;
    }
}