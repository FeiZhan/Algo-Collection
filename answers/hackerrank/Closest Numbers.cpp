//@result Submitted a few seconds ago • Score: 35.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0.07s

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_num = 0;
    while (cin >> num_num) {
        multiset<int> num_list;
        for (int i = 0; i < num_num; ++ i) {
            int num = 0;
            cin >> num;
            num_list.insert(num);
        }
        int min_diff = INT_MAX;
        int prev = INT_MAX;
        for (multiset<int>::iterator it = num_list.begin(); it != num_list.end(); ++ it) {
            min_diff = min(min_diff, abs(prev - *it));
            prev = *it;
        }
        bool first_flag = true;
        prev = INT_MAX;
        for (multiset<int>::iterator it = num_list.begin(); it != num_list.end(); ++ it) {
            if (abs(prev - *it) == min_diff) {
                cout << (first_flag ? "" : " ") << prev << " " << *it;
                first_flag = false;
            }
            prev = *it;
        }
        cout << endl;
    }
    return 0;
}
