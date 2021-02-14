class Solution {
    public String getSmallestString(int n, int k) {
        k -= n;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int digit = Math.min(k, 25);
            k -= digit;
            sb.insert(0, (char) (digit + 97));
        }
        return sb.toString();
    }
}