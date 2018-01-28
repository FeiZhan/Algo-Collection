class Solution {
    public int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int one = 1;
        int two = one + 1;
        int all = 0;
        for (int i = 2; i < n; i++) {
            all = one + two;
            one = two;
            two = all;
        }
        return all;
    }
}