class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> queens = new LinkedList<>();
        this.dfs(new LinkedList<>(), n, queens);
        return queens;
    }

    private void dfs(List<Integer> positions, int n, List<List<String>> queens) {
        if (positions.size() == n) {
            List<String> queen = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < n; j++) {
                    sb.append(j == positions.get(i) ? 'Q' : '.');
                }
                queen.add(sb.toString());
            }
            queens.add(queen);
        }

        for (int i = 0; i < n; i++) {
            boolean flag = true;
            for (int j = 0; j < positions.size(); j++) {
                if (i == positions.get(j) || i + positions.size() == j + positions.get(j) || i - positions.size() == positions.get(j) - j) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                positions.add(i);
                this.dfs(positions, n, queens);
                positions.remove(positions.size() - 1);
            }
        }
    }
}