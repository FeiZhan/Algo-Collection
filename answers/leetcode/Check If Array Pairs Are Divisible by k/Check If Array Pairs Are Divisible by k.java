class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] remainders = new int[k];
        for (int number : arr) {
            int remainder = number % k;
            while (remainder < 0) {
                remainder += k;
            }
            remainders[remainder]++;
        }
        for (int i = 1; i * 2 < k; i++) {
            if (remainders[i] != remainders[k - i]) {
                return false;
            }
        }
        return remainders[0] % 2 == 0;
    }
}