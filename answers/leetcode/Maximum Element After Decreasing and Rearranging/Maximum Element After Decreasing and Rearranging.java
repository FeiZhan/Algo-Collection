class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        int result = 0;

        for (int number : arr) {
            result = Math.min(result + 1, number);
        }

        return result;
    }
}