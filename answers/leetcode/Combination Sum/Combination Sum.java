class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> results = new LinkedList<>();
        for (int i = 0; i < candidates.length; i++) {
            backtrack(i, new LinkedList<>(), results, target, candidates);
        }

        return results;
    }

    private void backtrack(int current, List<Integer> combination, List<List<Integer>> results, int target, int[] candidates) {
        if (current >= candidates.length || target <= 0) {
            return;
        }

        target -= candidates[current];
        combination.add(candidates[current]);

        if (target == 0) {
            results.add(new LinkedList<>(combination));
        } else {
            for (int i = current; i < candidates.length; i++) {
                backtrack(i, combination, results, target, candidates);
            }
        }

        target += candidates[current];
        combination.remove(combination.size() - 1);
    }
}
//Runtime: 21 ms, faster than 7.39% of Java online submissions for Combination Sum.
//Memory Usage: 45.3 MB, less than 5.41% of Java online submissions for Combination Sum.
