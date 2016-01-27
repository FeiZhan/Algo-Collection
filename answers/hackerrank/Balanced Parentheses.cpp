//@result Submitted a few seconds ago • Score: 25.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0.01s Test Case #7: 0.01s Test Case #8: 0s Test Case #9: 0.01s Test Case #10: 0.03s Test Case #11: 0.04s Test Case #12: 0.03s Test Case #13: 0.04s Test Case #14: 0.03s Test Case #15: 0.04s Test Case #16: 0.03s Test Case #17: 0.03s Test Case #18: 0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int case_num = 0;
    cin >> case_num;
    while (case_num --) {
        string parentheses;
        cin >> parentheses;
        stack<char> parent_stack;
        bool flag = true;
        for (size_t i = 0; i < parentheses.length(); ++ i) {
            switch (parentheses[i]) {
            case '(':
            case '[':
            case '{':
                parent_stack.push(parentheses[i]);
                break;
            case ')':
                if (parent_stack.empty() || parent_stack.top() != '(') {
                    flag = false;
                }
                else {
                    parent_stack.pop();
                }
                break;
            case ']':
                if (parent_stack.empty() || parent_stack.top() != '[') {
                    flag = false;
                }
                else {
                    parent_stack.pop();
                }
                break;
            case '}':
                if (parent_stack.empty() || parent_stack.top() != '{') {
                    flag = false;
                }
                else {
                    parent_stack.pop();
                }
                break;
            }
            if (! flag) {
                break;
            }
        }
        cout << ((flag && parent_stack.empty()) ? "YES" : "NO") << endl;
    }
    return 0;
}
