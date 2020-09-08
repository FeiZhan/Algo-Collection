class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int count = 0;
        for (int number : arr) {
            if (number % 2 == 1) {
                count++;
            } else {
                count = 0;
            }
            if (count >= 3) {
                return true;
            }
        }
        return false;
    }
}