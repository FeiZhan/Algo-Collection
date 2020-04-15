class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (i >= k) {
                sum -= arr[i - k];
            }
            if (i + 1 >= k) {
                double average = sum * 1. / k;
                if (average >= threshold) {
                    count++;
                }
            }
        }
        return count;
    }
}