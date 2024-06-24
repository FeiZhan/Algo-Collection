class Solution {
    public int numberOfSpecialChars(String word) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (char c : word.toCharArray()) {
            if (Character.isLowerCase(c)) {
                if (!charMap.containsKey(c)) {
                    charMap.put(c, 1);
                } else if (charMap.get(c) == 2) {
                    charMap.put(c, -1);
                }
            } else if (Character.isUpperCase(c)) {
                char lowercase = Character.toLowerCase(c);
                if (!charMap.containsKey(lowercase)) {
                    charMap.put(lowercase, -1);
                } else if (charMap.get(lowercase) == 1) {
                    charMap.put(lowercase, 2);
                }
            }
        }

        int result = 0;
        for (int state : charMap.values()) {
            if (state == 2) {
                result++;
            }
        }

        return result;
    }
}