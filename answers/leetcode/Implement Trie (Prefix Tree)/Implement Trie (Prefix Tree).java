class Trie {
    
    private TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
        this.root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode current = this.root;
        for (char c : word.toCharArray()) {
            if (current.getChild(c) == null) {
                TrieNode next = new TrieNode();
                current.setChild(c, next);
            }
            current = current.getChild(c);
        }
        current.setEnd(true);
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode current = this.root;
        for (char c : word.toCharArray()) {
            TrieNode next = current.getChild(c);
            if (next == null) {
                return false;
            } else {
                current = next;
            }
        }
        return current.isEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode current = this.root;
        for (char c : prefix.toCharArray()) {
            TrieNode next = current.getChild(c);
            if (next == null) {
                return false;
            } else {
                current = next;
            }
        }
        return true;
    }
    
    private class TrieNode {
        
        private TrieNode[] children;
        private boolean isEnd;
        
        public TrieNode() {
            this.children = new TrieNode[26];
        }
        
        public void setChild(char c, TrieNode node) {
            this.children[c - 'a'] = node;
        }
        
        public TrieNode getChild(char c) {
            return this.children[c - 'a'];
        }
        
        public void setEnd(boolean isEnd) {
            this.isEnd = isEnd;
        }
        
        public boolean isEnd() {
            return this.isEnd;
        }
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */