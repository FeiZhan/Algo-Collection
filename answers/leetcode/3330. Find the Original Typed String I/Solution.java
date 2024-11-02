class Solution {
    public int possibleStringCount(String word) {
        int result = 1;
        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i - 1) == word.charAt(i)) {
                result++;
            }
        }

        return result;
    }
}