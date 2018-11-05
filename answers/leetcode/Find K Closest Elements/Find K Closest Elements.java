class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int left = 0;
        int right = arr.length;
        int index = -1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (arr[middle] <= x && (middle + 1 == arr.length || arr[middle + 1] >= x)) {
                index = middle;
                break;
            } else if (arr[middle] < x) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        List<Integer> result = new LinkedList<>();
        left = index;
        right = index + 1;
        while (result.size() < k) {
            int leftElement = left >= 0 ? arr[left] : Integer.MIN_VALUE;
            int rightElement = right < arr.length ? arr[right] : Integer.MAX_VALUE;
            if (left >= 0 && x - leftElement <= rightElement - x) {
                result.add(leftElement);
                left--;
            } else {
                result.add(rightElement);
                right++;
            }
        }
        Collections.sort(result);
        return result;
    }
}