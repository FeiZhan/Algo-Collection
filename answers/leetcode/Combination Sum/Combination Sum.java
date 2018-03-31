class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> combinations = new ArrayList<List<Integer>>();
        this.combinationSum(candidates, target, 0, new ArrayList<Integer>(), combinations);
        return combinations;
    }

    private void combinationSum(int[] candidates, int target, int index, List<Integer> combination, List<List<Integer>> combinations) {
        if (target == 0) {
            combinations.add(new ArrayList<Integer>(combination));
        }
        if (target <= 0) {
            return;
        }
        for (int i = index; i < candidates.length; i++) {
            combination.add(candidates[i]);
            this.combinationSum(candidates, target - candidates[i], i, combination, combinations);
            combination.remove(combination.size() - 1);
        }
    }
}