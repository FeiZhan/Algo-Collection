//@type Backtracking Trie Design
//@result 13 / 13 test cases passed. Status: Accepted Runtime: 160 ms Submitted: 0 minutes ago You are here! Your runtime beats 25.21% of cpp submissions.

#include <iostream>
#include <string>
using namespace std;

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

class WordDictionary {
public:
	WordDictionary(void) {
        root = new TrieNode();
	}
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *node = root;
		for (size_t i = 0; i < word.length(); ++ i) {
			if (! node->children[word[i] - 'a']) {
				node->children[word[i] - 'a'] = new TrieNode();
			}
			node = node->children[word[i] - 'a'];
		}
		node->key_flag = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
		return search(word, root, 0);
    }
    bool search(string word, TrieNode *node, size_t pos) {
		if (pos >= word.length()) {
			return node ? node->key_flag : false;
		}
		else if (node) {
			if ('.' == word[pos]) {
				for (size_t i = 0; i < 26; ++ i) {
					if (search(word, node->children[i], pos + 1)) {
						return true;
					}
				}
				return false;
			}
			else {
				return search(word, node->children[word[pos] - 'a'], pos + 1);
			}
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

int main() {
	// your code goes here
	WordDictionary wordDictionary;
	wordDictionary.addWord("a");
	wordDictionary.addWord("ab");
	cout << wordDictionary.search("a") << endl;
	cout << wordDictionary.search("a.") << endl;
	cout << wordDictionary.search("ab") << endl;
	cout << wordDictionary.search(".a") << endl;
	cout << wordDictionary.search(".b") << endl;
	cout << wordDictionary.search("ab.") << endl;
	cout << wordDictionary.search(".") << endl;
	cout << wordDictionary.search("..") << endl;
	return 0;
}