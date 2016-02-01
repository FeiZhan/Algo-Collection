//@result Submitted a few seconds ago • Score: 20.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0.02s Test Case #8: 0.07s Test Case #9: 0.08s Test Case #10: 0.07s Test Case #11: 0.07s Test Case #12: 0.07s Test Case #13: 0.08s Test Case #14: 0.07s Test Case #15: 0.06s Test Case #16: 0.07s Test Case #17: 0.11s Test Case #18: 0.11s Test Case #19: 0.11s Test Case #20: 0.1s Test Case #21: 0.11s Test Case #22: 0.1s Test Case #23: 0.11s Test Case #24: 0.11s Test Case #25: 0.11s Test Case #26: 0.11s Test Case #27: 0.1s

#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int oper_num = 0;
    cin >> oper_num;
    stack<int> oper_stack;
    stack<int> max_stack;
    for (int i = 0; i < oper_num; ++ i) {
        int type = 0;
        cin >> type;
        int target = 0;
        switch (type) {
        case 1:
            cin >> target;
            oper_stack.push(target);
            if (max_stack.empty() || target >= max_stack.top()) {
                max_stack.push(target);
            }
            break;
        case 2:
            target = oper_stack.top();
            oper_stack.pop();
            if (max_stack.top() == target) {
                max_stack.pop();
            }
            break;
        case 3:
            if (! max_stack.empty()) {
                cout << max_stack.top() << endl;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
