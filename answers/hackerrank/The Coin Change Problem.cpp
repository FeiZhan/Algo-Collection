//@result Submitted a few seconds ago • Score: 60.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Success Test Case #8: 0s Test Case #9: 0s Test Case #10: 0s Test Case #11: 0s Test Case #12: 0s Test Case #13: 0s Test Case #14: 0s Test Case #15: 0s Test Case #16: 0s
//@algorithm dp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    long long target = 0;
    long long coin_num = 0;
    while (cin >> target >> coin_num) {
        vector<long long> coin_list;
        for (long long i = 0; i < coin_num; ++ i) {
            long long coin = 0;
            cin >> coin;
            coin_list.push_back(coin);
        }
        sort(coin_list.begin(), coin_list.end(), greater<long long> ());
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (size_t i = 0; i < coin_list.size(); ++ i) {
            for (long long j = coin_list[i]; j <= target; ++ j) {
                dp[j] += dp[j - coin_list[i]];
            }
        }
        cout << dp.back() << endl;
    }
    return 0;
}
