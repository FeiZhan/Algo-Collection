//@result Submitted a few seconds ago • Score: 50.00 Status: Accepted Test Case #0: 0.07s Test Case #1: 0.06s Test Case #2: 0.04s Test Case #3: 0.06s Test Case #4: 0.07s Test Case #5: 0.07s Test Case #6: 0.05s Test Case #7: 0.05s Test Case #8: 0.07s Test Case #9: 0.08s Test Case #10: 0s
//@algorithm greedy

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    long long case_num = 0;
    cin >> case_num;
    while (case_num --) {
        long long day_num = 0;
        cin >> day_num;
        vector<long long> price_list;
        for (long long i = 0; i < day_num; ++ i) {
            long long price = 0;
            cin >> price;
            price_list.push_back(price);
        }
        long long profit = 0;
        long long max_price = INT_MIN;
        for (size_t i = price_list.size() - 1; i < price_list.size(); -- i) {
            max_price = max(max_price, price_list[i]);
            profit += max_price - price_list[i];
        }
        cout << profit << endl;
    }
    return 0;
}
