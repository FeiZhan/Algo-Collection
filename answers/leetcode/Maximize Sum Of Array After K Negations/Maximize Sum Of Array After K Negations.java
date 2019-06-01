class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        Arrays.sort(A);
        for (int i = 0; i < A.length && A[i] < 0 && K > 0; i++) {
            A[i] = -A[i];
            K--;
        }
        K %= 2;
        Arrays.sort(A);
        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            sum += A[i] * (i < K ? -1 : 1);
            K--;
        }
        return sum;
    }
}