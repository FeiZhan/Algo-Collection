class Solution {
    public int sumSubarrayMins(int[] arr) {
        int[] left = new int[arr.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            left[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }
        stack.clear();
        int[] right = new int[arr.length];
        for (int i = arr.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                stack.pop();
            }
            right[i] = stack.isEmpty() ? arr.length : stack.peek();
            stack.push(i);
        }
        long result = 0l;
        final long MOD = (long)1e9 + 7l;
        for (int i = 0; i < arr.length; i++) {
            result = (result + (long)(i - left[i]) * (right[i] - i) * arr[i]) % MOD;
        }

        return (int)result;
    }
}