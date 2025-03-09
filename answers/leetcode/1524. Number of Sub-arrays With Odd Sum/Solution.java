class Solution {
    public int numOfSubarrays(int[] arr) {
        final int MOD = 1_000_000_007;
        int sum = 0;
        int[] sums = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            sums[i] = sum;
        }
        int even = 0;
        int odd = 0;
        int result = 0;
        for (int i = 0; i < sums.length; i++) {
            if (sums[i] % 2 == 1) {
                result += even + 1;
                odd++;
            } else {
                result += odd;
                even++;
            }
            result %= MOD;
        }

        return result;
    }
}