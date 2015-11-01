//@type Trie Design
//@result 14 / 14 test cases passed. Status: Accepted Runtime: 60 ms Submitted: 2 minutes ago You are here! Your runtime beats 62.25% of cpp submissions.

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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
		for (size_t i = 0; i < word.length(); ++ i) {
			if (! node->children[word[i] - 'a']) {
				node->children[word[i] - 'a'] = new TrieNode();
			}
			node = node->children[word[i] - 'a'];
		}
		node->key_flag = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
		for (size_t i = 0; i < word.length(); ++ i) {
			if (node) {
				node = node->children[word[i] - 'a'];
			}
			else {
				break;
			}
		}
		return node ? node->key_flag : false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
		for (size_t i = 0; i < prefix.length(); ++ i) {
			if (node) {
				node = node->children[prefix[i] - 'a'];
			}
			else {
				break;
			}
		}
		return node;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");