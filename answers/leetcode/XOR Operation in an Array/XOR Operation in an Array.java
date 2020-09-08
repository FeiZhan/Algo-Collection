class Solution {
    public int xorOperation(int n, int start) {
        int xor = 0;
        for (int i = 0; i < n; i++) {
            int number = start + i + i;
            xor ^= number;
        }
        return xor;
    }
}