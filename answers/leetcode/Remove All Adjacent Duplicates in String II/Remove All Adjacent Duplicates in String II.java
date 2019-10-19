class Solution {
    public String removeDuplicates(String s, int k) {
        StringBuilder sb = new StringBuilder(s);
        boolean removed = true;
        while (removed) {
            removed = false;
            char c = sb.charAt(0);
            int count = 0;
            for (int i = 0; i < sb.length(); i++) {
                if (sb.charAt(i) == c) {
                    count++;
                } else {
                    c = sb.charAt(i);
                    count = 1;
                }
                if (count == k) {
                    sb.delete(i - k + 1, i + 1);
                    count = 0;
                    i -= k;
                    removed = true;
                }
            }
        }
        return sb.toString();
    }
}