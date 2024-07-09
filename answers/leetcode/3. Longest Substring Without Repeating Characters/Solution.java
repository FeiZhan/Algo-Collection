class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int longest = 0;
        Map<Character, Integer> charMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (charMap.containsKey(c)) {
                // The left may be larger than (charMap.get(c) + 1) .
                left = Math.max(left, charMap.get(c) + 1);
            }
            charMap.put(c, i);
            longest = Math.max(longest, i - left + 1);
        }

        return longest;
    }
}
//Runtime: 5 ms, faster than 81.88% of Java online submissions for Longest Substring Without Repeating Characters.
//Memory Usage: 38.8 MB, less than 94.53% of Java online submissions for Longest Substring Without Repeating Characters.
