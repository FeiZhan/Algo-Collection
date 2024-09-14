class Solution {
    public int[] decrypt(int[] code, int k) {
        int absoluteK = Math.abs(k);
        int length = code.length;
        int sum = 0;
        for (int i = 0; i < absoluteK; i++) {
            sum +=  k >= 0 ? code[i] : code[(length + k + i - 1) % length];
        }
        int[] result = new int[length];
        for (int i = 0; i < length; i++) {
            if (k >= 0) {
                sum += code[(i + k) % length] - code[i];
            } else {
                sum += code[(length + i - 1) % length] - code[(length + k + i - 1) % length];
            }
            result[i] = sum;
        }

        return result;
    }
}