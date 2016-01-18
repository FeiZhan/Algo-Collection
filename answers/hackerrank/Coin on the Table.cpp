//@result Submitted a few seconds ago • Score: 65.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s Test Case #10: 0s
//@algorithm dp

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int row = 0;
    int column = 0;
    int step = 0;
    while (cin >> row >> column >> step) {
        vector<string> table;
        for (int i = 0; i < row; ++ i) {
            string line;
            cin >> line;
            table.push_back(line);
        }
        vector<vector<vector<int> > > dp(step + 1, vector<vector<int> > (row, vector<int> (column, INT_MAX / 10)));
        dp[0][0][0] = 0;
        for (size_t i = 1; i < dp.size(); ++ i) {
            for (size_t j = 0; j < dp[i].size(); ++ j) {
                for (size_t k = 0; k < dp[i][j].size(); ++ k) {
                    if ('*' == table[j][k]) {
                        dp[i][j][k] = min(dp[i - 1][j][k], dp[i][j][k]);
                    }
                    if (j > 0) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k] + ('D' == table[j - 1][k] ? 0 : 1));
                    }
                    if (j + 1 < dp[i].size()) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + 1][k] + ('U' == table[j + 1][k] ? 0 : 1));
                    }
                    if (k > 0) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - 1] + ('R' == table[j][k - 1] ? 0 : 1));
                    }
                    if (k + 1 < dp[i][j].size()) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k + 1] + ('L' == table[j][k + 1] ? 0 : 1));
                    }
                }
            }
        }
        int min_change = INT_MAX / 10;
        for (size_t i = 0; i < table.size(); ++ i) {
            for (size_t j = 0; j < table[i].size(); ++ j) {
                if ('*' == table[i][j]) {
                    min_change = min(min_change, dp.back()[i][j]);
                }
            }
        }
        cout << (INT_MAX / 10 == min_change ? -1 : min_change) << endl;
    }
    return 0;
}
