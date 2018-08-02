class WordDictionary {
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
            return this.search(word, 0, this.root);
        }
        
        private boolean search(String word, int index, TrieNode current) {
            if (index >=  word.length()) {
                return current.isEnd();
            }
            char c = word.charAt(index);
            if (c == '.') {
                for (char i = 'a'; i < 'z'; i++) {
                    TrieNode next = current.getChild(i);
                    if (next != null && this.search(word, index + 1, next)) {
                        return true;
                    }
                }
                return false;
            } else {
                TrieNode next = current.getChild(c);
                return next != null && this.search(word, index + 1, next);
            }
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
    
    private Trie root;

    /** Initialize your data structure here. */
    public WordDictionary() {
        this.root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        this.root.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return this.root.search(word);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */