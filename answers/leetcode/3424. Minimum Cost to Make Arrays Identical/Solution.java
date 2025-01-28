class Solution {
    public long minCost(int[] arr, int[] brr, long k) {
        long diff = 0l;
        for (int i = 0; i < arr.length; i++) {
            diff += Math.abs(arr[i] - brr[i]);
        }
        Arrays.sort(arr);
        Arrays.sort(brr);
        long result = k;
        for (int i = 0; i < arr.length; i++) {
            result += Math.abs(arr[i] - brr[i]);
        }

        return Math.min(diff, result);
    }
}