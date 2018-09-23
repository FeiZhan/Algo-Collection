class Solution {
    public int totalNQueens(int n) {
        return this.dfs(new LinkedList<>(), n);
    }

    private int dfs(List<Integer> positions, int n) {
        if (positions.size() == n) {
            return 1;
        }

        int count = 0;
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
                count += this.dfs(positions, n);
                positions.remove(positions.size() - 1);
            }
        }
        return count;
    }
}
