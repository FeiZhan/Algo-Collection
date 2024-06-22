class Solution {
    public String getSmallestString(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            int left = c - 'a';
            int right = 'z' - c + 1;
            if (k < left && k < right) {
                sb.append((char)((int)c - k));
                k = 0;
            } else {
                sb.append('a');
                k -= Math.min(left, right);
            }
        }

        return sb.toString();
    }
}