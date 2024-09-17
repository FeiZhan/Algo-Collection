class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int left = 0;
        int ones = 0;
        int zeros = 0;
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                ones++;
            } else {
                zeros++;
            }
            while (ones > k && zeros > k) {
                if (s.charAt(left) == '1') {
                    ones--;
                } else {
                    zeros--;
                }
                left++;
            }
            result += i - left + 1;
        }

        return result;
    }
}