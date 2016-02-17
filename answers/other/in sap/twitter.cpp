// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.


/*
Given a string sentence and a dictionary of words, determine if the sentence can be segmented into a space-separated sequence of one or more words in the dictionary.

For example, given
sentence = "thisgame",
dictionary = {"i", "love", "this", "game", "nba", "nfl", ...}

Return true because "thisgame" can be segmented as "this game".

More examples:

hellogame -> false
ilove -> true
gamegame -> true
iihello -> false
*/

ABC
{A, B, C}
{AB, C}
{A, BC}
{ABC}

n
2 ^ (n-1) combinations


// O(n ^ 3)
// O(n ^ 2)
bool Segmentable(string &sentence, unordered_set<string> &dictionary) {
    vector<vector<bool> > dp(sentence.length(), vector<bool> (sentence.length(), false));
    for (size_t i = 0; i < sentence.length(); ++ i) {
        for (size_t j = 0; j < sentence.length(); ++ j) {
            if (dictionary.end() != dictionary.find(sentence.substr(i, j - i + 1))) {
                dp[i][j] = true;
            }
            else {
                for (size_t k = i; k <= j; ++ k) {
                    if (dp[i][k] && dp[k][j]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[0].back();
}


/*
clone a graph

A -> B -> C -> D
  \  ^   /
   v | v
     E
     
A -> B -> C -> D
  \  ^   /
   v | v
     E


*/
Node {
    int data;
    vector<Node *> edges;
}

// O(n)
// O(n)
Node* cloneGraph(const Node const *root){
    if (node_map.end() == node_map.find(root)) {
        if (NULL == root) {
            node_map.insert(make_pair(root, NULL)); // NULL -> NULL
        }
        else {
            node_map[root] = new Node(root->data);
            for (size_t i = 0; i < root->edges.size(); ++ i) {
                node_map[root]->edges[i] = cloneGraph(root->edges[i]);
            }
        }
    }
    return node_map[root];
}
unordered_map<Node *, Node *> node_map;




