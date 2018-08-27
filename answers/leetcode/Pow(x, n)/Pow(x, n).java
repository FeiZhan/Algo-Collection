class Solution {
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            return 1. / x * this.myPow(1 / x, - (n + 1));
        } else {
            return n % 2 == 0 ? this.myPow(x * x, n / 2) : x * this.myPow(x * x, n / 2);
        }
    }
}