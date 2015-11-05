/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : flag(false), children(26, NULL) {
        
    }
    bool flag;
    vector<TrieNode *> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *current = root;
        for (size_t i = 0; i < word.size(); ++ i) {
            if (NULL == current->children[(int) (word[i] - 'a')]) {
                current->children[(int) (word[i] - 'a')] = new TrieNode();
            }
            current = current->children[(int) (word[i] - 'a')];
        }
        current->flag = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *current = root;
        for (size_t i = 0; i < word.size(); ++ i) {
            if (NULL == current->children[(int) (word[i] - 'a')]) {
                return false;
            }
            current = current->children[(int) (word[i] - 'a')];
        }
        return current->flag;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *current = root;
        for (size_t i = 0; i < prefix.size(); ++ i) {
            if (NULL == current->children[(int) (prefix[i] - 'a')]) {
                return false;
            }
            current = current->children[(int) (prefix[i] - 'a')];
        }
        return true;
    }

private:
    TrieNode* root;
};
