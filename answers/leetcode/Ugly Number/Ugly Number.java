class Solution {
    public boolean isUgly(int num) {
        if (0 == num) {
            return false;
        } else if (1 == num) {
            return true;
        }

        final int[] factors = new int[]{2, 3, 5};
        for (int factor : factors) {
            while (num > 1 && num % factor == 0) {
                num /= factor;
            }
        }
        return num == 1;
    }
}