class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        this.backtrack(1, n, k, new ArrayList<>(), result);
        return result;
    }

    public void backtrack(int start, int end, int count, List<Integer> combination, List<List<Integer>> result) {
        if (combination.size() >= count) {
            result.add(new ArrayList<>(combination));
        } else {
            for (int i = start; i <= end; i++) {
                combination.add(i);
                this.backtrack(i + 1, end, count, combination, result);
                combination.remove(combination.size() - 1);
            }
        }
    }
}