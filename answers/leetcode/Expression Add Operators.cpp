//@result 20 / 20 test cases passed. Status: Accepted Runtime: 204 ms Submitted: 0 minutes ago You are here! Your runtime beats 80.46% of cpp submissions.
//@algorithm dfs

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> answers;
        string operation;
        dfs(0, 0, operation, num, target, answers);
        return answers;
    }
    // change all numbers to long long to avoid overflow
    void dfs(size_t pos, long long prev, string &operation, const string &num, long long target, vector<string> &answers) {
        if (pos >= num.length()) {
            if (0 == target) {
                answers.push_back(operation);
            }
            return;
        }
        long long current = 0;
        for (size_t i = pos; i < num.length(); ++ i) {
            // avoid numbers starting with 0, i.e. 01
            if ('0' == num[pos] && i > pos) {
                break;
            }
            current = current * 10 + static_cast<int> (num[i] - '0');
            if (pos > 0) {
                operation += "+";
            }
            operation += num.substr(pos, i - pos + 1);
            dfs(i + 1, current, operation, num, target - current, answers);
            operation.erase(operation.length() - (i - pos + 1));
            if (pos > 0) {
                operation.pop_back();
            }
            if (pos > 0) {
                operation += "-";
                operation += num.substr(pos, i - pos + 1);
                dfs(i + 1, - current, operation, num, target + current, answers);
                operation.erase(operation.length() - (i - pos + 2));
                operation += "*";
                operation += num.substr(pos, i - pos + 1);
                // keep previous result to respect precedence of multiplication
                dfs(i + 1, prev * current, operation, num, target + prev - prev * current, answers);
                operation.erase(operation.length() - (i - pos + 2));
            }
        }
    }
};
