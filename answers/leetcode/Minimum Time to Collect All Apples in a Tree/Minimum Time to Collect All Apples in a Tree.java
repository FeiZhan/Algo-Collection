class Solution {

    private class TreeNode {
        public boolean hasApple = false;
        public boolean visited = false;
        public List<Integer> connected = new ArrayList<>();
    }

    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        List<TreeNode> tree = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            TreeNode node = new TreeNode();
            node.hasApple = hasApple.get(i);
            tree.add(node);
        }
        for (int[] edge : edges) {
            TreeNode parent = tree.get(edge[0]);
            parent.connected.add(edge[1]);
            TreeNode child = tree.get(edge[1]);
            child.connected.add(edge[0]);
        }
        return this.dfs(0, tree);
    }

    private int dfs(int current, List<TreeNode> tree) {
        int time = 0;
        TreeNode node = tree.get(current);
        node.visited = true;
        for (int next : node.connected) {
            TreeNode nextNode = tree.get(next);
            if (nextNode.visited) {
                continue;
            }
            int childTime = this.dfs(next, tree);
            time += childTime + (childTime > 0 || nextNode.hasApple ? 2 : 0);
        }
        return time;
    }
}