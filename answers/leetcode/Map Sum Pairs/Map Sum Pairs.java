class MapSum {

    private TrieNode root = new TrieNode();
    private Map<String, Integer> values = new HashMap<>();

    /** Initialize your data structure here. */
    public MapSum() {
    }
    
    public void insert(String key, int val) {
        int diff = val - this.values.getOrDefault(key, 0);
        this.values.put(key, val);
        root.value += diff;
        TrieNode current = root;
        for (char c : key.toCharArray()) {
            if (!current.children.containsKey(c)) {
                current.children.put(c, new TrieNode());
            }
            current = current.children.get(c);
            current.value += diff;
        }
    }
    
    public int sum(String prefix) {
        TrieNode current = root;
        for (char c : prefix.toCharArray()) {
            if (!current.children.containsKey(c)) {
                return 0;
            }
            current = current.children.get(c);
        }
        return current.value;
    }

    private class TrieNode {
        public int value = 0;
        public Map<Character, TrieNode> children = new HashMap<>();
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */