class Solution {
    public int minOperations(int[] nums) {
        int op0 = 0;
        int op1 = 0;
        for (int number : nums) {
            op0 += Integer.bitCount(number);
            op1 = Math.max(op1, Integer.SIZE - Integer.numberOfLeadingZeros(number) - 1);
        }
        return op0 + op1;
    }
}