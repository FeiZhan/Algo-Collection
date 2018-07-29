class Solution {
    public int titleToNumber(String s) {
        int num = 0;
        for (char c : s.toCharArray()) {
            num = num * 26 + (int)(c - 'A' + 1);
        }
        return num;
    }
}