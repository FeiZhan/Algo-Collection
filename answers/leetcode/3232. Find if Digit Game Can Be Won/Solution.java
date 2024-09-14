class Solution {
    public boolean canAliceWin(int[] nums) {
        int singleSum = 0;
        int doubleSum = 0;
        for (int number : nums) {
            if (number < 10) {
                singleSum += number;
            } else {
                doubleSum += number;
            }
        }

        return singleSum != doubleSum;
    }
}