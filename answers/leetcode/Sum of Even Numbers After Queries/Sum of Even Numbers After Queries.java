class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int sum = 0;
        for (int number : A) {
            if (number % 2 == 0) {
                sum += number;
            }
        }
        int[] results = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int index = queries[i][1];
            int value = queries[i][0];
            int old = A[index];
            boolean oldEven = old % 2 == 0;
            A[index] += value;
            boolean newEven = A[index] % 2 == 0;
            if (oldEven) {
                if (newEven) {
                    sum += value;
                } else {
                    sum -= old;
                }
            } else if (newEven) {
                sum += A[index];
            }
            results[i] = sum;
        }
        return results;
    }
}