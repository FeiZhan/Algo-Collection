class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int left = 0;
        int right = A.length - 1;
        while (left < right) {
            int middle = (left + right) / 2;
            if ((middle == 0 || A[middle - 1] < A[middle]) && (middle == A.length - 1 || A[middle] < A[middle + 1])) {
                left = middle + 1;
            } else if ((middle == 0 || A[middle - 1] > A[middle]) && (middle == A.length - 1 || A[middle] > A[middle + 1])) {
                right = middle - 1;
            } else {
                return middle;
            }
        }
        return right;
    }
}