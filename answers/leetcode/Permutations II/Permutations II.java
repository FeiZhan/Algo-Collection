class Solution {
    
    private int count;
    private List<List<Integer>> permutations;
    private Map<Integer, Integer> nums;
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        this.count = nums.length;
        this.nums = new HashMap<>();
        for (int num : nums) {
            this.nums.put(num, this.nums.getOrDefault(num, 0) + 1);
        }
        this.permutations = new LinkedList<List<Integer>>();
        this.backtrack(new LinkedList<>(), new HashMap<>());
        return this.permutations;
    }
    
    private void backtrack(List<Integer> permutation, Map<Integer, Integer> map) {
        if (permutation.size() == this.count) {
            this.permutations.add(new LinkedList<>(permutation));
        } else {
            for (Map.Entry<Integer, Integer> entry : nums.entrySet()) {
                if (!map.containsKey(entry.getKey()) || map.get(entry.getKey()) < entry.getValue()) {
                    permutation.add(entry.getKey());
                    map.put(entry.getKey(), map.getOrDefault(entry.getKey(), 0) + 1);
                    this.backtrack(permutation, map);
                    permutation.remove(permutation.size() - 1);
                    map.put(entry.getKey(), map.get(entry.getKey()) - 1);
                }
            }
        }
    }
}