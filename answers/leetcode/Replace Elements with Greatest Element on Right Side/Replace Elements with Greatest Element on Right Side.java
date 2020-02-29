class Solution {
    public int[] replaceElements(int[] arr) {
        int greatest = -1;
        for (int i = arr.length - 1; i >= 0; i--) {
            int next = Math.max(greatest, arr[i]);
            arr[i] = greatest;
            greatest = next;
        }
        return arr;
    }
}