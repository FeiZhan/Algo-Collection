class Solution {
    public long countSubstrings(String s, char c) {
        long count = 0l;
        for (char character : s.toCharArray()) {
            count += character == c ? 1l : 0l;
        }

        return count * (count + 1l) / 2l;
    }
}