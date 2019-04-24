class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int left = 0;
        int right = 1;
        int max = 0;
        for (int i = 1; i < A.length; i++) {
            if (A[i] - i > A[right] - right) {
                right = i;
            }
            max = Math.max(max, A[left] + left + A[right] - right);
            //System.out.println(i + ": " + left + " " + right + " = " + max);
            if (A[i] + i > A[left] + left) {
                left = i;
                right = i + 1;
            }
        }
        return max;
    }
}