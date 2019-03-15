class Solution {
    public int longestMountain(int[] A) {
        int left = 0;
        int longest = 0;
        int type = 0;
        for (int i = 1; i <= A.length; i++) {
            if (i == A.length || A[i - 1] == A[i]) {
                if (type == -1) {
                    longest = Math.max(longest, i - left);
                }
                type = 0;
                left = i;
            } else if (A[i - 1] < A[i]) {
                if (type == -1) {
                    longest = Math.max(longest, i - left);
                }
                if (type != 1) {
                    type = 1;
                    left = i - 1;
                }
            } else if (type == 1) {
                type = -1;
            }
        }
        return longest >= 3 ? longest : 0;
    }
}