class Solution {
    public boolean validMountainArray(int[] A) {
        boolean up = true;
        for (int i = 1; i < A.length; i++) {
            if (A[i - 1] < A[i]) {
                if (!up) {
                    return false;
                }
            } else if (A[i - 1] > A[i]) {
                if (i <= 1) {
                    return false;
                } else if (up) {
                    up = false;
                }
            } else {
                return false;
            }
        }
        return !up;
    }
}