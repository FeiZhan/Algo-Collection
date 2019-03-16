class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        long sum = 0;
        StringBuilder sb = new StringBuilder(S);
        for (int i = shifts.length - 1; i >= 0; i--) {
            sum += shifts[i];
            char c = (char)(((long)sb.charAt(i) - (long)'a' + sum) % 26 + (long)'a');
            sb.setCharAt(i, c);
        }
        return sb.toString();
    }
}