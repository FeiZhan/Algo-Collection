class Solution {
    public int numSubarrayBoundedMax(int[] A, int L, int R) {
        int result = 0;
        int left = -1;
        int right = -1;
        for (int i = 0; i < A.length; i++) {
            if (A[i] > R) {
                left = i;
                right = i;
            } else {
                if (A[i] >= L) {
                    right = i;
                }
                result += right - left;
            }
        }
        return result;
    }
}