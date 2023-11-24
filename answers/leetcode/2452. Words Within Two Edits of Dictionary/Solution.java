class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        TrieNode root = new TrieNode();
        for (String word : dictionary) {
            add(root, word);
        }

        List<String> result = new LinkedList<>();
        for (String word : queries) {
            if (query(root, word, 0, 2)) {
                result.add(word);
            }
        }

        return result;
    }

    private class TrieNode {
        public boolean isLeaf = false;
        public Map<Character, TrieNode> children = new HashMap<>();
    }

    private void add(TrieNode root, String word) {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            TrieNode next = current.children.getOrDefault(c, new TrieNode());
            current.children.put(c, next);
            current = next;
        }
        current.isLeaf = true;
    }

    private boolean query(TrieNode root, String word, int index, int count) {
        if (index >= word.length()) {
            return true;
        }

        char c = word.charAt(index);
        if (root.children.containsKey(c) && query(root.children.get(c), word, index + 1, count)) {
            return true;
        } else if (count > 0) {
            for (TrieNode next : root.children.values()) {
                if (query(next, word, index + 1, count - 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return false;
        }
    }
}