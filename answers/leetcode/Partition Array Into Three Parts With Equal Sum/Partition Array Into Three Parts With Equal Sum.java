class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for (int number : A) {
            sum += number;
        }
        if (sum % 3 != 0) {
            return false;
        }
        int addition = 0;
        int count = 0;
        for (int i = 0; i < A.length; i++) {
            addition += A[i];
            if (addition * 3 == sum) {
                count++;
                addition = 0;
                if (count >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
}