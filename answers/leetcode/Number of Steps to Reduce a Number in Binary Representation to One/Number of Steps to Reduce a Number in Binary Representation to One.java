class Solution {
    public int numSteps(String s) {
        int carry = 0;
        int steps = 0;
        for (int i = s.length() - 1; i > 0; i--) {
            char c = s.charAt(i);
            if (c == '0') {
                steps += 1 + carry;
            } else if (c == '1') {
                steps += 2 - carry;
                carry = 1;
            }
        }
        return steps + carry;
    }
}