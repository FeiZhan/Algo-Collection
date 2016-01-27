//@result Submitted a few seconds ago • Score: 30.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0.01s Test Case #5: 0.01s Test Case #6: 0.01s Test Case #7: 0.02s Test Case #8: 0s Test Case #9: 0s Test Case #10: 0s Test Case #11: 0s Test Case #12: 0s Test Case #13: 0s Test Case #14: 0s Test Case #15: 0s Test Case #16: 0.02s Test Case #17: 0.02s Test Case #18: 0.02s Test Case #19: 0.02s Test Case #20: 0.02s Test Case #21: 0.02s Test Case #22: 0.03s Test Case #23: 0.03s

#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(int num, const vector<int> &group_list) {
    int sum = 0;
    for (size_t j = 0; j < group_list.size(); ++ j) {
        sum += group_list[j];
        if (sum == num) {
            sum = 0;
        }
        else if (sum > num || j + 1 == group_list.size()) {
            return false;
        }
    }
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int group_num = 0;
    while (cin >> group_num) {
        vector<int> group_list(group_num, 0);
        int group_sum = 0;
        for (size_t i = 0; i < group_list.size(); ++ i) {
            cin >> group_list[i];
            group_sum += group_list[i];
        }
        set<int> bus_list;
        // cut time complexity by square root
        for (int i = 1; i * i <= group_sum; ++ i) {
            if (0 == group_sum % i) {
                if (check(i, group_list)) {
                    bus_list.insert(i);
                }
                if (i != group_sum / i && check(group_sum / i, group_list)) {
                    bus_list.insert(group_sum / i);
                }
            }
        }
        for (set<int>::iterator it = bus_list.begin(); it != bus_list.end(); ++ it) {
            cout << (bus_list.begin() == it ? "" : " ") << *it;
        }
        cout << endl;
    }
    return 0;
}
