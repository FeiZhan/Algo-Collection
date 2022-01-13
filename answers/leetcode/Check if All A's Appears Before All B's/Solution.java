class Solution {
    public boolean checkString(String s) {
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == 'b' && s.charAt(i) == 'a') {
                return false;
            }
        }

        return true;
    }
}
//Runtime: 1 ms, faster than 33.33% of Java online submissions for Check if All A's Appears Before All B's.
//Memory Usage: 38.6 MB, less than 16.67% of Java online submissions for Check if All A's Appears Before All B's.
