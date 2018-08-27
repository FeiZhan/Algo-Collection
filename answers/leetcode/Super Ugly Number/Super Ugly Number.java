class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] ugly = new int[n];
        int[] indexes = new int[primes.length];
        int[] values = new int[primes.length];
        Arrays.fill(values, 1);
        int next = 1;
        for (int i = 0; i < n; i++) {
            ugly[i] = next;
            next = Integer.MAX_VALUE;
            for (int j = 0; j < primes.length; j++) {
                if (values[j] == ugly[i]) {
                    values[j] = ugly[indexes[j]] * primes[j];
                    indexes[j]++;
                }
                next = Math.min(next, values[j]);
            }
        }
        return ugly[n - 1];
    }
}