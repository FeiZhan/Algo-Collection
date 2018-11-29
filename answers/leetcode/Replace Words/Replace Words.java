class Solution {

    private class TrieNode {
        public TrieNode[] children;
        public boolean isLeaf;

        public TrieNode() {
            this.children = new TrieNode[26];
            this.isLeaf = false;
        }
    }
    public String replaceWords(List<String> dict, String sentence) {
        TrieNode root = new TrieNode();
        for (String word : dict) {
            TrieNode current = root;
            for (char c : word.toCharArray()) {
                if (current.children[c - 'a'] == null) {
                    current.children[c - 'a'] = new TrieNode();
                }
                current = current.children[c - 'a'];
            }
            current.isLeaf = true;
        }
        String[] words = sentence.split(" ");
        StringBuilder result = new StringBuilder();
        for (String word : words) {
            TrieNode current = root;
            StringBuilder rootWord = new StringBuilder();
            for (char c : word.toCharArray()) {
                if (current.children[c - 'a'] != null) {
                    rootWord.append(c);
                    current = current.children[c - 'a'];
                    if (current.isLeaf) {
                        break;
                    }
                } else {
                    break;
                }
            }
            result.append(current.isLeaf ? rootWord : word).append(" ");
        }
        if (result.length() > 0) {
            result.deleteCharAt(result.length() - 1);
        }
        return result.toString();
    }
}