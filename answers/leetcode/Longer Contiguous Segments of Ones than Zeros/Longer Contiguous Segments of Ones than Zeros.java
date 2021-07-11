class Solution {
    public boolean checkZeroOnes(String s) {
        boolean isOne = false;
        int left = 0;
        int ones = 0;
        int zeros = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (isOne ^ (c == '1')) {
                left = i;
                isOne = c == '1';
            }

            if (isOne) {
                ones = Math.max(ones, i - left + 1);
            } else {
                zeros = Math.max(zeros, i - left + 1);
            }
        }

        return ones > zeros;
    }
}