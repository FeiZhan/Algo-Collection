class Solution {
    public int findNthDigit(int n) {
        int length = 1;
        long count = 9;
        int start = 1;
        while (n > length * count) {
            n -= length * count;
            length++;
            count *= 10;
            start *= 10;
        }
        start += (n - 1) / length;
        String numStr = Integer.toString(start);
        char numChar = numStr.charAt((n - 1) % length);
        return Character.getNumericValue(numChar);
    }
}