class Solution {
    public int distributeCandies(int n, int limit) {
        int result = 0;
        for (int i = 0; i <= n && i <= limit; i++) {
            for (int j = 0; i + j <= n && j <= limit; j++) {
                int rest = n - i - j;
                if (rest <= n && rest <= limit) {
                    result++;
                }
            }
        }

        return result;
    }
}