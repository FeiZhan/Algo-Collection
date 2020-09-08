class Solution {
    public String thousandSeparator(int n) {
        StringBuilder sb = new StringBuilder(Integer.toString(n));
        for (int i = sb.length() - 3; i > 0; i -= 3) {
            sb.insert(i, '.');
        }
        return sb.toString();
    }
}