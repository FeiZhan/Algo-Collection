class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int[] result = new int[2];
        result[0] = S.length() > 0 ? 1 : 0;
        for (char c : S.toCharArray()) {
            if (result[1] + widths[c - 'a'] > 100) {
                result[0]++;
                result[1] = 0;
            }
            result[1] += widths[c - 'a'];
        }
        return result;
    }
}