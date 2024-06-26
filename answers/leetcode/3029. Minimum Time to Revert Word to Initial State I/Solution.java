class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        int length = word.length();
        for (int i = 1; i * k < length; i++) {
            String substring = word.substring(i * k);
            if (substring.equals(word.substring(0, substring.length()))) {
                return i;
            }
        }

        return (int)Math.ceil((double)length / (double)k);
    }
}