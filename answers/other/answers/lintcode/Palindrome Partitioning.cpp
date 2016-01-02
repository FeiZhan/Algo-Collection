#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<bool> > dp(s.length(), vector<bool> (s.length(), false));
        for (size_t i = 0; i < s.length(); ++ i) {
            for (size_t j = 0; i + j < s.length(); ++ j) {
                dp[j][i + j] = 0 == i || (1 == i && s[j] == s[j + i]) || (dp[j + 1][i + j - 1] && s[j] == s[j + i]);
            }
        }
        vector<size_t> part;
        vector<vector<size_t> > part_list;
        dfs(0, part, part_list, dp);
        vector<vector<string> > str_list;
        for (size_t i = 0; i < part_list.size(); ++ i) {
            vector<string> str;
            size_t prev = 0;
            for (size_t j = 0; j < part_list[i].size(); ++ j) {
                str.push_back(s.substr(prev, part_list[i][j] - prev + 1));
                prev = part_list[i][j] + 1;
            }
            str_list.push_back(str);
        }
        return str_list;
    }
    void dfs(size_t current, vector<size_t> part, vector<vector<size_t> > &part_list, const vector<vector<bool> > &dp) {
        //cout << "debug " << current << endl;
        if (current >= dp.size()) {
            part_list.push_back(part);
            return;
        }
        for (size_t i = 0; i < dp[current].size(); ++ i) {
            if (dp[current][i]) {
                part.push_back(i);
                dfs(i + 1, part, part_list, dp);
                part.pop_back();
            }
        }
    }
};

int main() {
	// your code goes here
    Solution s;
    string str("ab");
    vector<vector<string>> ans = s.partition(str);
    for (size_t i = 0; i < ans.size(); ++ i) {
        for (size_t j = 0; j < ans[i].size(); ++ j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
