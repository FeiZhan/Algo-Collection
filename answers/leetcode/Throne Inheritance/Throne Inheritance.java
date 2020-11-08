class ThroneInheritance {

    private class TreeNode {

        public boolean isDead = false;
        public String name;
        public TreeNode parent;
        public List<TreeNode> children = new LinkedList<>();

        public TreeNode(TreeNode parent, String name) {
            this.name = name;
            this.parent = parent;
        }
    }

    private TreeNode king;
    private Map<String, TreeNode> names = new HashMap<>();

    public ThroneInheritance(String kingName) {
        this.king = new TreeNode(null, kingName);
        this.names.put(kingName, this.king);
    }

    public void birth(String parentName, String childName) {
        TreeNode parent = this.names.get(parentName);
        TreeNode child = new TreeNode(parent, childName);
        parent.children.add(child);
        this.names.put(childName, child);
    }

    public void death(String name) {
        TreeNode current = this.names.get(name);
        current.isDead = true;
    }

    public List<String> getInheritanceOrder() {
        List<String> result = new LinkedList<>();
        this.dfs(this.king, result);
        return result;
    }

    private void dfs(TreeNode current, List<String> result) {
        if (!current.isDead) {
            result.add(current.name);
        }
        for (TreeNode children : current.children) {
            this.dfs(children, result);
        }
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.birth(parentName,childName);
 * obj.death(name);
 * List<String> param_3 = obj.getInheritanceOrder();
 */