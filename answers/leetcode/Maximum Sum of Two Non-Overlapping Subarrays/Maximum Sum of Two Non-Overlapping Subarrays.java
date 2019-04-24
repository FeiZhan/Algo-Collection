class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        return Math.max(this.maxSum(A, L, M), this.maxSum(A, M, L));
    }

    private int maxSum(int[] A, int L, int M) {
        int[] leftDp = new int[A.length];
        int sum = 0;
        for (int i = 0; i < L; i++) {
            sum += A[i];
        }
        leftDp[L - 1] = sum;
        for (int i = L; i < A.length; i++) {
            sum += - A[i - L] + A[i];
            leftDp[i] = Math.max(leftDp[i - 1], sum);
        }
        int[] rightDp = new int[A.length];
        sum = 0;
        for (int i = 0; i < M; i++) {
            sum += A[A.length - 1 - i];
        }
        rightDp[A.length - M] = sum;
        for (int i = A.length - 1 - M; i >= 0; i--) {
            sum += - A[i + M] + A[i];
            rightDp[i] = Math.max(rightDp[i + 1], sum);
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i + 1 < A.length; i++) {
            max = Math.max(max, leftDp[i] + rightDp[i + 1]);
            //System.out.println(i + ": " + leftDp[i] + " + " + rightDp[i + 1] + " = " + max);
        }
        return max;
    }
}