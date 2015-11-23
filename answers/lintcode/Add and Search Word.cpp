class WordDictionary {
public:
    class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode() : key_flag(false) {
            for (int i = 0; i < 26; ++ i) {
    			children[i] = NULL;
    		}
        }
    	bool key_flag;
    	TrieNode *children[26];
    };
    WordDictionary(void) {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        TrieNode *current = root;
        for (size_t i = 0; i < word.length(); ++ i) {
            if (NULL == current->children[word[i] - 'a']) {
                current->children[word[i] - 'a'] = new TrieNode();
            }
            current = current->children[word[i] - 'a'];
        }
        current->key_flag = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return search(word, 0, root);
    }
    bool search(const string &word, size_t current, TrieNode *node) {
        if (current >= word.length() || NULL == node) {
            return node && node->key_flag;
        }
        else if (word[current] >= 'a' && word[current] <= 'z') {
            return search(word, current + 1, node->children[word[current] - 'a']);
        }
        else if ('.' == word[current]) {
            for (int i = 0; i < 26; ++ i) {
                if (search(word, current + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        }
        else {
            return false;
        }
    }
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
