class Solution {
    public int minFlips(String target) {
        char bit = '0';
        int result = 0;
        for (char c : target.toCharArray()) {
            if (c != bit) {
                result++;
                bit = c;
            }
        }

        return result;
    }
}