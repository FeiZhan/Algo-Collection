#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);
        unordered_map<string, vector<unordered_set<string>::iterator> > word_map;
        queue<unordered_set<string>::iterator> word_queue;
        word_queue.push(wordList.find(beginWord));
        bool end_flag = false;
        while (! word_queue.empty() && ! end_flag) {
            size_t size = word_queue.size();
            for (size_t i = 0; i < size; ++ i) {
                unordered_set<string>::iterator current = word_queue.front();
                word_queue.pop();
                if (wordList.find(endWord) == current) {
                    end_flag = true;
                    break;
                }
                if (word_map.end() == word_map.find(*current)) {
                    word_map.insert(make_pair(*current, vector<unordered_set<string>::iterator> ()));
                }
                for (unordered_set<string>::iterator it = wordList.begin(); it != wordList.end(); ++ it) {
                    if (word_map.end() == word_map.find(*it) && current->length() == it->length()) {
                        int count = 0;
                        for (size_t j = 0; j < current->length(); ++ j) {
                            if (current->at(j) != it->at(j)) {
                                ++ count;
                            }
                            if (count > 1) {
                                break;
                            }
                        }
                        if (1 == count) {
                            word_map[*current].push_back(it);
                            word_queue.push(it);
                        }
                    }
                }
            }
        }
        word_queue = queue<unordered_set<string>::iterator> ();
        vector<string> sequence;
        vector<vector<string> > sequence_list;
        dfs(wordList.find(beginWord), sequence, wordList.find(endWord), word_map, sequence_list);
        return sequence_list;
    }
    void dfs(unordered_set<string>::iterator current, vector<string> &sequence, const unordered_set<string>::iterator &end, unordered_map<string, vector<unordered_set<string>::iterator> > &word_map, vector<vector<string> > &sequence_list) {
        sequence.push_back(*current);
        if (end == current) {
            sequence_list.push_back(sequence);
            return;
        }
        for (size_t i = 0; i < word_map[*current].size(); ++ i) {
            dfs(word_map[*current][i], sequence, end, word_map, sequence_list);
        }
        sequence.pop_back();
    }
};


int main() {
	// your code goes here
    Solution s;
    //beginWord = "hit"
    //endWord = "cog"
    //wordList = ["hot","dot","dog","lot","log"]
    string beginWord("hit");
    string endWord("cog");
    unordered_set<string> wordList;
    wordList.insert(string("hot"));
    s.findLadders(beginWord, endWord, wordList);
	return 0;
}
