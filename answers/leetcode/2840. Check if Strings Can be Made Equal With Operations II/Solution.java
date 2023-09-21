class Solution {
    public boolean checkStrings(String s1, String s2) {
        if (s1 == null || s2 == null || s1.length() != s2.length()) {
            return false;
        }

        int length = s1.length();
        Map<Character, Integer> charMap = new HashMap<>();
        for (int i = 0; i < length; i += 2) {
            char c = s1.charAt(i);
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }
        for (int i = 0; i < length; i += 2) {
            char c = s2.charAt(i);
            if (!charMap.containsKey(c)) {
                return false;
            }
            charMap.put(c, charMap.get(c) - 1);
            if (charMap.get(c) == 0) {
                charMap.remove(c);
            }
        }

        charMap = new HashMap<>();
        for (int i = 1; i < length; i += 2) {
            char c = s1.charAt(i);
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }
        for (int i = 1; i < length; i += 2) {
            char c = s2.charAt(i);
            if (!charMap.containsKey(c)) {
                return false;
            }
            charMap.put(c, charMap.get(c) - 1);
            if (charMap.get(c) == 0) {
                charMap.remove(c);
            }
        }

        return true;
    }
}