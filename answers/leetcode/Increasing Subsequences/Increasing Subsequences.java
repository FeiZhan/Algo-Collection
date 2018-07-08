class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> subsequences = new HashSet<>();
        this.dfs(-1, new LinkedList<>(), subsequences, nums);
        return new ArrayList<>(subsequences);
    }

    private void dfs(int index, LinkedList<Integer> subsequence, Set<List<Integer>> subsequences, int[] nums) {
        for (int i = index + 1; i < nums.length; i++) {
            if (index < 0 || nums[i] >= nums[index]) {
                subsequence.add(nums[i]);
                if (subsequence.size() >= 2) {
                    subsequences.add(new ArrayList<>(subsequence));
                }
                this.dfs(i, subsequence, subsequences,nums);
                subsequence.removeLast();
            }
        }
    }
}