class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        int carry = 0;
        List<Integer> result = new LinkedList<>();
        for (int i = A.length - 1; i >= 0; i--) {
            carry += A[i] + K % 10;
            result.add(0, carry % 10);
            carry /= 10;
            K /= 10;
        }
        carry += K;
        while (carry > 0) {
            result.add(0, carry % 10);
            carry /= 10;
        }
        return result;
    }
}