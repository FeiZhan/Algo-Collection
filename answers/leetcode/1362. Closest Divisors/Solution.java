class Solution {
    public int[] closestDivisors(int num) {
        int[] result1 = closest(num + 1);
        int[] result2 = closest(num + 2);

        return Math.abs(result1[0] - result1[1]) < Math.abs(result2[0] - result2[1])
            ? result1 : result2;
    }

    private int[] closest(double number) {
        for (int i = (int) Math.sqrt(number); i >= 0; i--) {
            int divisor = (int) number / i;
            if (divisor * i == (int) number) {
                return new int[] {i, divisor};
            }
        }
        return new int[] {-1, (int) number};
    }
}