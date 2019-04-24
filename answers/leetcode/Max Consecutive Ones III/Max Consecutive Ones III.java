class Solution {
    public int longestOnes(int[] A, int K) {
        int count = 0;
        int left = 0;
        int result = 0;
        for (int i = 0; i < A.length; i++) {
            if (A[i] == 0) {
                count++;
                while (count > K) {
                    if (A[left] == 0) {
                        count--;
                    }
                    left++;
                }
            }
            result = Math.max(result, i - left + 1);
        }
        return result;
    }
}