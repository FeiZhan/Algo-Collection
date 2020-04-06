class Solution {
    public int minSwap(int[] A, int[] B) {
        int[] noswap = new int[A.length];
        int[] swap = new int[A.length];
        swap[0] = 1;
        for (int i = 1; i < A.length; i++) {
            noswap[i] = Integer.MAX_VALUE;
            swap[i] = Integer.MAX_VALUE;
        }
        for (int i = 1; i < A.length; i++) {
            if (A[i - 1] < A[i] && B[i - 1] < A[i] && A[i - 1] < B[i] && B[i - 1] < B[i]) {
                noswap[i] = Math.min(noswap[i - 1], swap[i - 1]);
                swap[i] = noswap[i] + 1;
            } else if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                noswap[i] = noswap[i - 1];
                swap[i] = swap[i - 1] + 1;
            } else if (B[i - 1] < A[i] && A[i - 1] < B[i]) {
                noswap[i] = swap[i - 1];
                swap[i] = noswap[i - 1] + 1;
            }
        }
        return Math.min(noswap[A.length - 1], swap[A.length - 1]);
    }
}