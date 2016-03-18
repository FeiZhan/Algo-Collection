//@result 150 / 150 test cases passed. Status: Accepted Runtime: 16 ms Submitted: 0 minutes ago You are here! Your runtime beats 9.83% of cppsubmissions.

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<char> tree_stack;
        stringstream iss(preorder);
        string token;
        vector<string> tokens;
        while(getline(iss, token, ',')) {
           tokens.push_back(token);
        }
        for (size_t i = 0; i < tokens.size(); ++ i) {
            if ('#' == tokens[i][0]) {
                while (tree_stack.size() >= 2 && '#' == tree_stack.back() && '#' != tree_stack[tree_stack.size() - 2]) {
                    tree_stack.pop_back();
                    tree_stack.pop_back();
                }
                tree_stack.push_back('#');
            }
            else {
                tree_stack.push_back(tokens[i][0]);
            }
        }
        return 0 == tree_stack.size() || (1 == tree_stack.size() && '#' == tree_stack[0]);
    }
};