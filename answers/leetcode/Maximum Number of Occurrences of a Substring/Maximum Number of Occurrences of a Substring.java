class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int length = s.length();
        Map<Character, Integer> charMap = new HashMap<>();
        Map<String, Integer> stringMap = new HashMap<>();
        for (int i = 0; i < length; i++) {
            char c = s.charAt(i);
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);

            if (i >= minSize) {
                char c1 = s.charAt(i - minSize);
                int count = charMap.get(c1);
                if (count == 1) {
                    charMap.remove(c1);
                } else {
                    charMap.put(c1, count - 1);
                }
            }

            if (i >= minSize - 1 && charMap.size() <= maxLetters) {
                String substring = s.substring(i - minSize + 1, i + 1);
                stringMap.put(substring, stringMap.getOrDefault(substring, 0) + 1);
            }
        }

        int result = 0;
        for (int count : stringMap.values()) {
            result = Math.max(result, count);
        }

        return result;
    }
}
//Runtime: 38 ms, faster than 86.53% of Java online submissions for Maximum Number of Occurrences of a Substring.
//Memory Usage: 40.7 MB, less than 98.95% of Java online submissions for Maximum Number of Occurrences of a Substring.
