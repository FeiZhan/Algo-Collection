class Solution {
    public int balancedStringSplit(String s) {
        int count = 0;
        int result = 0;
        for (char c : s.toCharArray()) {
            count += c == 'L' ? 1 : -1;
            result += count == 0 ? 1 : 0;
        }
        return result;
    }
}