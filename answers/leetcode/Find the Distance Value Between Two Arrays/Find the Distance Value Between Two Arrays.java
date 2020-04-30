class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int count = 0;
        for (int number1 : arr1) {
            int distance = Integer.MAX_VALUE;
            for (int number2 : arr2) {
                distance = Math.min(distance, Math.abs(number1 - number2));
            }
            if (distance > d) {
                count++;
            }
        }
        return count;
    }
}