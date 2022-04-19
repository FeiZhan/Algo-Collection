class Solution {
    public int triangularSum(int[] nums) {
        int[] current = nums;
        while (current.length > 1) {
            int[] next = new int[current.length - 1];
            for (int i = 0; i < next.length; i++) {
                next[i] = (current[i] + current[i + 1]) % 10;
            }
            current = next;
        }

        return current.length > 0 ? current[0] : 0;
    }
}
//Runtime: 90 ms, faster than 75.59% of Java online submissions for Find Triangular Sum of an Array.
//Memory Usage: 42.5 MB, less than 89.51% of Java online submissions for Find Triangular Sum of an Array.
