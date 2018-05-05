class Solution {
    public int numDecodings(String s) {
        int num0 = 1;
        int num1 = 1;
        for (int i = 0; i < s.length(); i++) {
            int num = 0;
            if (s.charAt(i) > '0') {
                num += num1;
            }
            if (i > 0 && ((s.charAt(i - 1) > '0' && s.charAt(i - 1) <= '1') || (s.charAt(i - 1) == '2' && s.charAt(i) <= '6'))) {
                num += num0;
            }
            num0 = num1;
            num1 = num;
        }
        return num1;
    }
}