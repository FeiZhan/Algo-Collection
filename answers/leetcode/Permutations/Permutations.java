class Solution {
    
    private int[] nums;
    private List<List<Integer>> permutations;
    
    public List<List<Integer>> permute(int[] nums) {
        this.nums = nums;
        this.permutations = new LinkedList<>();
        this.backtrack(new LinkedList<>(), new HashSet<>());
        return this.permutations;
    }
    
    private void backtrack(List<Integer> permutation, Set<Integer> set) {
        if (permutation.size() == this.nums.length) {
            this.permutations.add(new LinkedList<>(permutation));
        } else {
            for (int num : nums) {
                if (!set.contains(num)) {
                    permutation.add(num);
                    set.add(num);
                    this.backtrack(permutation, set);
                    permutation.remove(permutation.size() - 1);
                    set.remove(num);
                }
            }
        }
    }
}