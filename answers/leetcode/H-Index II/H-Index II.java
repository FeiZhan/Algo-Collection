class Solution {
    public int hIndex(int[] citations) {
        int length = citations.length;
        int left = 0;
        int right = length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (citations[middle] < length - middle) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return length - left;
    }
}