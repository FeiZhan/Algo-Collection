class Solution {
    public int countTestedDevices(int[] batteryPercentages) {
        int count = 0;
        for (int percentage : batteryPercentages) {
            if (percentage > count) {
                count++;
            }
        }

        return count;
    }
}