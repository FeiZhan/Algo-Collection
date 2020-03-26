class Solution {

    private class TrieNode {

        private List<String> words = new LinkedList<>();
        private TrieNode[] children = null;

        public void add(String word) {
            this.add(0, word);
        }

        private void add(int index, String word) {
            if (index >= word.length()) {
                this.words.add(word);
                return;
            }
            if (this.children == null) {
                this.children = new TrieNode[26];
            }
            int charIndex = word.charAt(index) - 'a';
            if (this.children[charIndex] == null) {
                this.children[charIndex] = new TrieNode();
            }
            this.children[charIndex].add(index + 1, word);
        }

        public List<String> search(String prefix) {
            return this.search(0, prefix);
        }

        private List<String> search(int index, String prefix) {
            if (index >= prefix.length()) {
                return this.getAll(3);
            } else if (this.children == null) {
                return new LinkedList<>();
            }
            int charIndex = prefix.charAt(index) - 'a';
            TrieNode child = this.children[charIndex];
            if (child == null) {
                return new LinkedList<>();
            }
            return child.search(index + 1, prefix);
        }

        private List<String> getAll(int limit) {
            List<String> result = new LinkedList<>(this.words);
            if (result.size() < limit && this.children != null) {
                for (TrieNode child : children) {
                    if (child != null) {
                        result.addAll(child.getAll(limit - result.size()));
                    }
                    if (result.size() >= limit) {
                        break;
                    }
                }
            }
            if (result.size() > limit) {
                result = result.subList(0, 3);
            }
            return result;
        }
    }

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        TrieNode root = new TrieNode();
        for (String product : products) {
            root.add(product);
        }
        List<List<String>> result = new LinkedList<>();
        for (int i = 0; i < searchWord.length(); i++) {
            result.add(root.search(searchWord.substring(0, i + 1)));
        }
        return result;
    }
}