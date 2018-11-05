class Solution {
    public boolean isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while (left <= right) {
            long middle = (long)(left + right) >>> 1;
            long square = middle * middle;
            if (square == num) {
                return true;
            } else if (square < num) {
                left = (int)middle + 1;
            } else {
                right = (int)middle - 1;
            }
        }
        return false;
    }
}