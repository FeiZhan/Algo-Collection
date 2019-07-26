class Solution {
    public void duplicateZeros(int[] arr) {
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            count += arr[i] == 0 ? 1 : 0;
        }
        for (int i = arr.length - 1 + count; i >= count; i--) {
            if (i < arr.length) {
                arr[i] = arr[i - count];
            }
            //System.out.println(i + " " + count + " " + arr[i - count]);
            if (arr[i - count] == 0) {
                count--;
                i--;
                if (i < arr.length && i >= 0) {
                    arr[i] = 0;
                }
            }
        }
    }
}