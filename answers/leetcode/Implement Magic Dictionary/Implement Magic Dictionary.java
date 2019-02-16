class MagicDictionary {

    private Map<String, Set<String>> dict = new HashMap<>();

    /** Initialize your data structure here. */
    public MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    public void buildDict(String[] dict) {
        for (String word : dict) {
            for (int i = 0; i < word.length(); i++) {
                StringBuilder sb = new StringBuilder(word);
                sb.setCharAt(i, '?');
                String modified = sb.toString();
                Set<String> wordSet = this.dict.getOrDefault(modified, new HashSet<>());
                wordSet.add(word);
                this.dict.put(modified, wordSet);
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    public boolean search(String word) {
        for (int i = 0; i < word.length(); i++) {
            StringBuilder sb = new StringBuilder(word);
            sb.setCharAt(i, '?');
            String modified = sb.toString();
            if (this.dict.containsKey(modified)) {
                Set<String> wordSet = this.dict.get(modified);
                if (wordSet.size() > 1 || !wordSet.contains(word)) {
                    return true;
                }
            }
        }
        return false;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */