class Solution {
    public int countSubstrings(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count += this.countSubstrings(i, i, s) + this.countSubstrings(i, i + 1, s);
        }
        return count;
    }

    private int countSubstrings(int left, int right, String s) {
        if (left < 0 || right >= s.length() || s.charAt(left) != s.charAt(right)) {
            //System.out.println(left + " " + right);
            return (right - left) / 2;
        }
        return this.countSubstrings(left - 1, right + 1, s);
    }
}