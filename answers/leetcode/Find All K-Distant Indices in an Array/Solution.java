class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        SortedSet<Integer> result = new TreeSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == key) {
                int start = Math.max(i - k, 0);
                int end = Math.min(i + k, nums.length - 1);
                for (int j = start; j <= end; j++) {
                    result.add(j);
                }
            }
        }

        return new LinkedList<>(result);
    }
}
//Runtime: 684 ms, faster than 5.01% of Java online submissions for Find All K-Distant Indices in an Array.
//Memory Usage: 87.8 MB, less than 17.64% of Java online submissions for Find All K-Distant Indices in an Array.
