class Solution {
    public int maxRotateFunction(int[] A) {
        int sum = Arrays.stream(A).sum();
        int fn = 0;
        for (int i = 0; i < A.length; i++) {
            fn += A[i] * i;
        }
        int max = fn;
        for (int i = A.length - 1; i > 0; i--) {
            fn += sum - A[i] * A.length;
            //System.out.println(fn + " " + max);
            max = Math.max(max, fn);
        }
        return max;
    }
}