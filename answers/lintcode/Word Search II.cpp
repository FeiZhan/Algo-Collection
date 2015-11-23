class Solution {
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
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        Trie trie;
        for (size_t i = 0; i < words.size(); ++ i) {
            trie.insert(words[i]);
        }
        string current;
        vector<vector<bool> > visit_list(board.size(), vector<bool> (board[0].size(), false));
        set<string> find_list;
        for (size_t i = 0; i < board.size(); ++ i) {
            for (size_t j = 0; j < board[i].size(); ++ j) {
                dfs(i, j, current, visit_list, board, trie, find_list);
            }
        }
        return vector<string> (find_list.begin(), find_list.end());
    }
    void dfs(size_t x, size_t y, string current, vector<vector<bool> > &visit_list, const vector<vector<char> > &board, Trie &trie, set<string> &find_list) {
        if (trie.search(current)) {
            find_list.insert(current);
        }
        if (x >= board.size() || y >= board[x].size() || visit_list[x][y]) {
            return;
        }
        current += board[x][y];
        //cout << "debug " << x << " " << y << " " << current << " " << trie.startsWith(current) << endl;
        if (trie.startsWith(current)) {
            visit_list[x][y] = true;
            dfs(x - 1, y, current, visit_list, board, trie, find_list);
            dfs(x + 1, y, current, visit_list, board, trie, find_list);
            dfs(x, y - 1, current, visit_list, board, trie, find_list);
            dfs(x, y + 1, current, visit_list, board, trie, find_list);
            visit_list[x][y] = false;
        }
    }
};
