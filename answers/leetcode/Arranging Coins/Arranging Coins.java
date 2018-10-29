class Solution {
    public int arrangeCoins(int n) {
        return (int) (-0.5 + Math.sqrt(1 + 8 * (long) n) / 2.0);
    }
}