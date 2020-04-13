class Solution {
    public int[] prevPermOpt1(int[] A) {
        int left = -1;
        int minRight = Integer.MAX_VALUE;
        for (int i = A.length - 1; i >= 0; i--) {
            if (A[i] > minRight) {
                left = i;
                break;
            }
            minRight = Math.min(minRight, A[i]);
        }
        if (left == -1) {
            return A;
        }
        int right = -1;
        for (int i = left + 1; i < A.length; i++) {
            if (A[i] < A[left] && (right == -1 || A[i] > A[right])) {
                right = i;
            }
        }
        int temp = A[left];
        A[left] = A[right];
        A[right] = temp;
        return A;
    }
}