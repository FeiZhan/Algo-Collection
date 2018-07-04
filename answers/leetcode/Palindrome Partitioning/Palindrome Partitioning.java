class Solution {
    public List<List<String>> partition(String s) {
        boolean[][] isPalim = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; i + j < s.length(); j++) {
                if (i == 0) {
                    isPalim[j][j + i] = true;
                } else if (i == 1) {
                    isPalim[j][j + i] = s.charAt(j) == s.charAt(j + i);
                } else {
                    isPalim[j][j + i] = isPalim[j + 1][j + i - 1] && s.charAt(j) == s.charAt(j + i);
                }
            }
        }
        
        List<List<String>> partitioned = new LinkedList<>();
        this.dfs(s, isPalim, 0, new LinkedList<>(), partitioned);
        return partitioned;
    }
    
    private void dfs(String s, boolean[][] isPalim, int start, List<String> partition, List<List<String>> partitioned) {
        if (start >= s.length()) {
            partitioned.add(new LinkedList<>(partition));
            return;
        }
        
        for (int i = start; i < isPalim[start].length; i++) {
            if (isPalim[start][i]) {
                partition.add(s.substring(start, i + 1));
                this.dfs(s, isPalim, i + 1, partition, partitioned);
                partition.remove(partition.size() - 1);
            }
        }
    }
}