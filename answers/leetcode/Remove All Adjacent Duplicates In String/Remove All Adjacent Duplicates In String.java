class Solution {
    public String removeDuplicates(String S) {
        StringBuilder sb = new StringBuilder(S);
        for (int i = 1; i < sb.length(); i++) {
            while (i >= 1 && sb.charAt(i) == sb.charAt(i - 1)) {
                sb.delete(i - 1, i + 1);
                i = Math.max(i - 2, 0);
            }
        }
        return sb.toString();
    }
}