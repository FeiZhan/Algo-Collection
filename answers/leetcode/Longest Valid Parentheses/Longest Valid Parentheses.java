class Solution {
    public int longestValidParentheses(String s) {
        return Math.max(this.helper(s, '('), this.helper(new StringBuilder(s).reverse().toString(), ')'));
    }
    
    private int helper(String s, char parenthesis) {
        int left = 0;
        int right = 0;
        int longest = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == parenthesis) {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                longest = Math.max(longest, left + right);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        return longest;
    }
}