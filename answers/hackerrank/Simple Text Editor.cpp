//@result Submitted a few seconds ago • Score: 65.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0.67s Test Case #8: 0.7s Test Case #9: 0.77s Test Case #10: 0.81s Test Case #11: 0.58s Test Case #12: 0.33s Test Case #13: 0.2s Test Case #14: 0.14s Test Case #15: 0.05s

#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct Operation {
    int type;
    string input;
    int num;
    Operation(void) : type(0), num(0) {}
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int oper_num = 0;
    cin >> oper_num;
    stack<Operation> oper_stack;
    vector<char> editor_stack;
    stack<char> undo_stack;
    for (int i = 0; i < oper_num; ++ i) {
        Operation oper;
        cin >> oper.type;
        Operation prev;
        switch (oper.type) {
        case 1:
            cin >> oper.input;
            for (size_t j = 0; j < oper.input.length(); ++ j) {
                editor_stack.push_back(oper.input[j]);
            }
            oper_stack.push(oper);
            break;
        case 2:
            cin >> oper.num;
            for (size_t j = 0; j < oper.num; ++ j) {
                undo_stack.push(editor_stack.back());
                editor_stack.pop_back();
            }
            oper_stack.push(oper);
            break;
        case 3:
            cin >> oper.num;
            cout << editor_stack[oper.num - 1] << endl;
            break;
        case 4:
            prev = oper_stack.top();
            oper_stack.pop();
            switch (prev.type) {
            case 1:
                for (size_t j = 0; j < prev.input.length(); ++ j) {
                    editor_stack.pop_back();
                }
                break;
            case 2:
                for (size_t j = 0; j < prev.num; ++ j) {
                    editor_stack.push_back(undo_stack.top());
                    undo_stack.pop();
                }
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
