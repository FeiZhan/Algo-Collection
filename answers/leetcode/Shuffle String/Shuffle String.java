class Solution {
    public String restoreString(String s, int[] indices) {
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < indices.length; i++) {
            char c = s.charAt(i);
            sb.setCharAt(indices[i], c);
        }
        return sb.toString();
    }
}