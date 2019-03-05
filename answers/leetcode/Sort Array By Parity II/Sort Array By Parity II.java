class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int even = 0;
        int odd = 1;
        while (even < A.length && odd < A.length) {
            if (A[even] % 2 == 0) {
                even += 2;
            } else if (A[odd] % 2 == 1) {
                odd += 2;
            } else {
                int temp = A[even];
                A[even] = A[odd];
                A[odd] = temp;
            }
        }
        return A;
    }
}