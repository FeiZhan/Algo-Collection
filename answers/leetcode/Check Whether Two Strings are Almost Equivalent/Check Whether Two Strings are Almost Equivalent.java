class Solution {
    public boolean checkAlmostEquivalent(String word1, String word2) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (char c : word1.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }
        for (char c : word2.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) - 1);
        }

        for (int count : charMap.values()) {
            if (count > 3 || count < -3) {
                return false;
            }
        }
        return true;
    }
}