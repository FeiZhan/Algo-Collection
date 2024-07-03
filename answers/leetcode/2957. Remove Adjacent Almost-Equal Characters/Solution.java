class Solution {
    public int removeAlmostEqualCharacters(String word) {
        int result = 0;
        for (int i = 1; i < word.length(); i++) {
            if (Math.abs(word.charAt(i - 1) - word.charAt(i)) <= 1) {
                i++;
                result++;
            }
        }

        return result;
    }
}