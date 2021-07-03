class Solution {
    public boolean makeEqual(String[] words) {
        Map<Character, Integer> letters = new HashMap<>();
        for (String word : words) {
            for (char c : word.toCharArray()) {
                letters.put(c, letters.getOrDefault(c, 0) + 1);
            }
        }

        for (int count : letters.values()) {
            if (count % words.length != 0) {
                return false;
            }
        }

        return true;
    }
}