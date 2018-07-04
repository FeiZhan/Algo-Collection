class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> combinations = new LinkedList<>();
        this.dfs(k, n, 1, new LinkedList<>(), combinations);
        return combinations;
    }
    
    private void dfs(int depth, int sum, int start, List<Integer> combi, List<List<Integer>> combinations) {
        if (depth <= 0 || start > 9 || sum <= 0) {
            if (depth == 0 && sum == 0) {
                combinations.add(new LinkedList<>(combi));
            }
            return;
        }
        
        for (int i = start; i <= 9; i++) {
            combi.add(i);
            this.dfs(depth - 1, sum - i, i + 1, combi, combinations);
            combi.remove(combi.size() - 1);
        }
    }
}