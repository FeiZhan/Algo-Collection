class Solution {
    public int minimumLengthEncoding(String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) {
            TrieNode current = root;
            for (int i = word.length() - 1; i >= 0; i--) {
                char c = word.charAt(i);
                if (!current.children.containsKey(c)) {
                    current.children.put(c, new TrieNode());
                }
                current = current.children.get(c);
            }
        }
        return this.count(root, 0);
    }

    private int count(TrieNode root, int depth) {
        int sum = 0;
        if (root != null) {
            for (TrieNode child : root.children.values()) {
                sum += this.count(child, depth + 1);
            }
            if (sum == 0) {
                sum = depth + 1;
            }
        }
        return sum;
    }

    private class TrieNode {
        public Map<Character, TrieNode> children = new HashMap<>();
    }
}