class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> answers;
        string parenthesis;
        generateParenthesis(0, parenthesis, n, answers);
        return answers;
    }
    void generateParenthesis(int left, string &parenthesis, const int n, vector<string> &answers) {
        if (left == n && parenthesis.length() == n + n) {
            answers.push_back(parenthesis);
            return;
        }
        if (left < n) {
            parenthesis += '(';
            generateParenthesis(left + 1, parenthesis, n, answers);
            parenthesis.pop_back();
        }
        if (left + left > parenthesis.length()) {
            parenthesis += ')';
            generateParenthesis(left, parenthesis, n, answers);
            parenthesis.pop_back();
        }
    }
};