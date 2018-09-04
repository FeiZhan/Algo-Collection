class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Map<Integer, Integer> candidateMap = new HashMap<>();
        for (int candidate : candidates) {
            candidateMap.put(candidate, candidateMap.getOrDefault(candidate, 0) + 1);
        }
        List<Integer> candidateList = new ArrayList<>(candidateMap.keySet());
        List<List<Integer>> combinations = new LinkedList<>();
        List<Integer> combination = new LinkedList<>();
        for (int i = 0; i < candidateList.size(); i++) {
            this.dfs(i, combination, combinations, candidateMap, candidateList, target);
        }
        return combinations;
    }
    
    private void dfs(int index, List<Integer> combination, List<List<Integer>> combinations, Map<Integer, Integer> candidateMap, List<Integer> candidateList, int target) {
        if (index >= candidateList.size()) {
            return;
        }
        int candidate = candidateList.get(index);
        for (int i = 0; i < candidateMap.get(candidate); i++) {
            combination.add(candidate);
            target -= candidate;
            if (target == 0) {
                combinations.add(new LinkedList<>(combination));
            } else if (target > 0) {
                for (int j = index + 1; j < candidateList.size(); j++) {
                    this.dfs(j, combination, combinations, candidateMap, candidateList, target);
                }
            }
        }
        for (int i = 0; i < candidateMap.get(candidate); i++) {
            combination.remove(combination.size() - 1);
        }
    }
}