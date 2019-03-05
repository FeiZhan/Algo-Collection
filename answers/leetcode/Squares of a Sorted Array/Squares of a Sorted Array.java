class Solution {
    public int[] sortedSquares(int[] A) {
        int left = 0;
        int right = A.length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (A[middle] < 0) {
                left = middle + 1;
            } else if (A[middle] > 0) {
                right = middle - 1;
            } else {
                break;
            }
        }
        left = (left + right) / 2;
        right = left + 1;
        List<Integer> list = new LinkedList<>();
        while (left >= 0 || right < A.length) {
            if (right >= A.length || (left >= 0 && Math.abs(A[left]) <= Math.abs(A[right]))) {
                list.add(A[left] * A[left]);
                left--;
            } else {
                list.add(A[right] * A[right]);
                right++;
            }
        }
        int[] results = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            results[i] = list.get(i);
        }
        return results;
    }
}