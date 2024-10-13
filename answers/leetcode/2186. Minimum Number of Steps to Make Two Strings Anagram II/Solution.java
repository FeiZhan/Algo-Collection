class Solution {
    public int minSteps(String s, String t) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }
        for (char c : t.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) - 1);
        }
        int result = 0;
        for (int count : charMap.values()) {
            result += Math.abs(count);
        }

        return result;
    }
}