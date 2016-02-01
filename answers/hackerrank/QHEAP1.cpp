//@result Submitted a few seconds ago • Score: 25.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0.01s Test Case #8: 0.1s Test Case #9: 0.09s Test Case #10: 0s Test Case #11: 0.12s Test Case #12: 0.12s Test Case #13: 0.11s Test Case #14: 0.12s Test Case #15: 0.13s Test Case #16: 0.12s Test Case #17: 0.12s Test Case #18: 0.12s

#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int oper_num = 0;
    cin >> oper_num;
    multiset<int> num_set;
    for (int i = 0; i < oper_num; ++ i) {
        int type = 0;
        cin >> type;
        int value = 0;
        pair<multiset<int>::iterator, multiset<int>::iterator> range;
        switch (type) {
        case 1:
            cin >> value;
            num_set.insert(value);
            break;
        case 2:
            cin >> value;
            range = num_set.equal_range(value);
            if(range.first != range.second) {
                num_set.erase(range.first);
            }
            break;
        case 3:
            cout << * num_set.begin() << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
