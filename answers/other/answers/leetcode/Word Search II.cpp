//@type Backtracking Trie
//@result 35 / 35 test cases passed. Status: Accepted Runtime: 164 ms Submitted: 0 minutes ago You are here! Your runtime beats 15.73% of cpp submissions.

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : key_flag(false) {
        for (int i = 0; i < MAX; ++ i) {
			children[i] = NULL;
		}
    }
	void clear(void) {
		for (int i = 0; i < MAX; ++ i) {
			if (children[i]) {
				children[i]->clear();
				delete children[i];
				children[i] = NULL;
			}
		}
	}
	const static int MAX = 27;
	bool key_flag;
	TrieNode *children[MAX];
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

	void clear(void) {
		if (root) {
			root->clear();
			delete root;
			root = new TrieNode();
		}
	}
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		trie.clear();
		for (size_t i = 0; i < words.size(); ++ i) {
			trie.insert(words[i]);
		}
		word_list.clear();
		for (size_t i = 0; i < board.size(); ++ i) {
			for (size_t j = 0; j < board[i].size(); ++ j) {
				findWords(board, i, j, string(""));
			}
		}
		return vector<string> (word_list.begin(), word_list.end());
	}
	void findWords(vector<vector<char> > &board, size_t x, size_t y, string prefix) {
		if (x >= board.size() || y >= board[x].size()) {
			return;
		}
		//cout << "test1 " << x << " " << y << " " << prefix << " " << trie.startsWith(prefix) << " " << trie.search(prefix) << endl;
		prefix += board[x][y];
		if (trie.startsWith(prefix)) {
			if (trie.search(prefix)) {
				word_list.insert(prefix);
			}
			char temp = board[x][y];
			board[x][y] = 'z' + 1;
			findWords(board, x - 1, y, prefix);
			findWords(board, x + 1, y, prefix);
			findWords(board, x, y - 1, prefix);
			findWords(board, x, y + 1, prefix);
			board[x][y] = temp;
		}
	}
	set<string> word_list;
	Trie trie;
};