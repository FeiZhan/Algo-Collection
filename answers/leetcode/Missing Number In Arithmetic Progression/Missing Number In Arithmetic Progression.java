class Solution {
    public int missingNumber(int[] arr) {
        int diff = arr[0] - arr[1];
        for (int i = 2; i < arr.length; i++) {
            int temp = arr[i - 1] - arr[i];
            if (temp == diff * 2) {
                return arr[i] + diff;
            } else if (diff == temp * 2) {
                return arr[1] + temp;
            }
        }
        return -1;
    }
}