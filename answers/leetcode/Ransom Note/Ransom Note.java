class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> notes = new HashMap<Character, Integer>();
        for (char letter : magazine.toCharArray()) {
            if (! notes.containsKey(letter)) {
                notes.put(letter, 0);
            }
            notes.put(letter, notes.get(letter) + 1);
        }
        for (char letter : ransomNote.toCharArray()) {
            if (notes.containsKey(letter)) {
                notes.put(letter, notes.get(letter) - 1);
                if (notes.get(letter) < 0) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
}