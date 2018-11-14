class Solution {
    private static final int BASE = 1337;

    public int superPow(int a, int[] b) {
        if (b == null || b.length == 0) {
            return 1;
        }
        return this.superPow(a, b, b.length - 1);
    }

    private int superPow(int a, int[] b, int index) {
        if (index < 0) {
            return 1;
        }
        int digit = b[index];
        return this.pow(this.superPow(a, b, index - 1), 10) * this.pow(a, digit) % BASE;
    }

    private int pow(int a, int b) {
        a %= BASE;
        int result = 1;
        for (int i = 0; i < b; i++) {
            result = (result * a) % BASE;
        }
        return result;
    }
}