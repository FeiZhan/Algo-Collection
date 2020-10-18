class Solution {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        int omit = (int) (arr.length * 0.05);
        double sum = 0.0;
        for (int i = omit; i < arr.length - omit; i++) {
            sum += arr[i];
        }
        return sum / (arr.length - omit - omit);
    }
}