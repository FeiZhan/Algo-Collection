//@result Submitted a few seconds ago • Score: 55.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Success Test Case #3: 0s
//@algorithm dp
//@todo space can be improved

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int length0 = 0;
    int length1 = 0;
    while (cin >> length0 >> length1) {
        vector<int> num0_list(length0, 0);
        for (size_t i = 0; i < num0_list.size(); ++ i) {
            cin >> num0_list[i];
        }
        vector<int> num1_list(length1, 0);
        for (size_t i = 0; i < num1_list.size(); ++ i) {
            cin >> num1_list[i];
        }
        vector<vector<int> > dp(length0, vector<int> (length1, 0));
        vector<vector<int> > backtrack(length0, vector<int> (length1, 0));
        for (size_t i = 0; i < dp.size(); ++ i) {
            for (size_t j = 0; j < dp[i].size(); ++ j) {
                if (i && dp[i][j] < dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j];
                    backtrack[i][j] = 1;
                }
                if (j && dp[i][j] < dp[i][j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                    backtrack[i][j] = 2;
                }
                if (num0_list[i] == num1_list[j] && dp[i][j] < 1 + (i && j ? dp[i - 1][j - 1] : 0)) {
                    dp[i][j] = 1 + (i && j ? dp[i - 1][j - 1] : 0);
                    backtrack[i][j] = 3;
                }
            }
        }
        size_t i = dp.size() - 1;
        size_t j = dp[i].size() - 1;
        vector<int> common;
        while (i < dp.size() && j < dp[i].size()) {
            //cout << "debug " << i << " " << j << " " << dp[i][j] << " " << backtrack[i][j] << endl;
            switch (backtrack[i][j]) {
            case 1:
                -- i;
                break;
            case 2:
                -- j;
                break;
            case 3:
                common.push_back(num0_list[i]);
                -- i;
                -- j;
                break;
            default:
                break;
            }
        }
        for (size_t i = common.size() - 1; i < common.size(); -- i) {
            cout << common[i] << (i ? " " : "");
        }
        cout << endl;
    }
    return 0;
}
