class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int factor = 1;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            factor <<= 1;
        }
        return m * factor;
    }
}