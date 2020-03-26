class Solution {
    public int minFlips(int a, int b, int c) {
        int count = 0;
        while (a > 0 || b > 0 || c > 0) {
            boolean a0 = a % 2 == 1;
            boolean b0 = b % 2 == 1;
            boolean c0 = c % 2 == 1;
            if (!a0 && !b0 && c0) {
                count++;
            } else if (((a0 && !b0) || (!a0 && b0)) && !c0) {
                count++;
            } else if (a0 && b0 && !c0) {
                count += 2;
            }

            a /= 2;
            b /= 2;
            c /= 2;
        }
        return count;
    }
}