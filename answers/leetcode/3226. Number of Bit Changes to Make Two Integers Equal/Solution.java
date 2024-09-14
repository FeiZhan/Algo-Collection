class Solution {
    public int minChanges(int n, int k) {
        return ((n ^ -1) & k) == 0 ? Integer.bitCount(n & (k ^ -1)) : -1;
    }
}