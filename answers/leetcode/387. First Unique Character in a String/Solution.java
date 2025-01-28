class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> letters = new HashMap<Character, Integer>();
        char[] sentence = s.toCharArray();
        for (char letter : sentence) {
            if (! letters.containsKey(letter)) {
                letters.put(letter, 0);
            }
            letters.put(letter, letters.get(letter) + 1);
        }
        for (int i = 0; i < sentence.length; i++) {
            if (letters.get(sentence[i]) == 1) {
                return i;
            }
        }
        return -1;
    }
}