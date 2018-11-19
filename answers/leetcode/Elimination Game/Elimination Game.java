class Solution {
    public int lastRemaining(int n) {
        boolean fromLeft = true;
        int head = 1;
        int step = 1;
        while (n > 1) {
            if (fromLeft || n % 2 == 1) {
                head += step;
            }
            n /= 2;
            step *= 2;
            fromLeft = !fromLeft;
        }
        return head;
    }
}