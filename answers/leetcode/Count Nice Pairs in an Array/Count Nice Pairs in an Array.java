class Solution {
    public int countNicePairs(int[] nums) {
        final int MOD = (int)1e9 + 7;

        int result = 0;
        Map<Integer, Integer> counts = new HashMap<>();

        for (int number : nums) {
            int reverse = 0;
            int temp = number;
            while (temp > 0) {
                reverse = reverse * 10 + temp % 10;
                temp /= 10;
            }
            int difference = number - reverse;
            int count = counts.getOrDefault(difference, 0) % MOD;
            counts.put(difference, count + 1);
            result = (result + count) % MOD;
        }

        return result;
    }
}