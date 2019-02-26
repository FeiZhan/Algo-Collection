class Solution {
    public boolean isMonotonic(int[] A) {
        int type = 0;
        for (int i = 1; i < A.length; i++) {
            if (A[i] > A[i - 1]) {
                if (type == -1) {
                    return false;
                } else if (type == 0) {
                    type = 1;
                }
            } else if (A[i] < A[i - 1]) {
                if (type == 1) {
                    return false;
                } else if (type == 0) {
                    type = -1;
                }
            }
        }
        return true;
    }
}