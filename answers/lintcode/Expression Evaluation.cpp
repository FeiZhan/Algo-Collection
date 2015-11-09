#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        stack<int> num_stack;
        stack<char> op_stack;
        for (size_t i = 0; i < expression.size(); ++ i) {
            switch (expression[i][0]) {
            case '+':
            case '-':
                while (! op_stack.empty() && ('+' == op_stack.top() || '-' == op_stack.top() || '*' == op_stack.top() || '/' == op_stack.top())) {
                    char op = op_stack.top();
                    op_stack.pop();
                    int num0 = num_stack.top();
                    num_stack.pop();
                    int num1 = num_stack.top();
                    num_stack.pop();
                    num_stack.push(eval(num0, num1, op));
                }
                op_stack.push(expression[i][0]);
                break;
            case '*':
            case '/':
                while (! op_stack.empty() && ('*' == op_stack.top() || '/' == op_stack.top())) {
                    char op = op_stack.top();
                    op_stack.pop();
                    int num0 = num_stack.top();
                    num_stack.pop();
                    int num1 = num_stack.top();
                    num_stack.pop();
                    num_stack.push(eval(num0, num1, op));
                }
                op_stack.push(expression[i][0]);
                break;
            case '(':
                op_stack.push(expression[i][0]);
                break;
            case ')':
                while (! op_stack.empty() && '(' != op_stack.top()) {
                    char op = op_stack.top();
                    op_stack.pop();
                    int num0 = num_stack.top();
                    num_stack.pop();
                    int num1 = num_stack.top();
                    num_stack.pop();
                    num_stack.push(eval(num0, num1, op));
                }
                if ('(' == op_stack.top()) {
                    op_stack.pop();
                }
                break;
            default:
                num_stack.push(atoi(expression[i].c_str()));
                break;
            }
        }
        while (! op_stack.empty()) {
            char op = op_stack.top();
            op_stack.pop();
            int num0 = num_stack.top();
            num_stack.pop();
            int num1 = num_stack.top();
            num_stack.pop();
            num_stack.push(eval(num0, num1, op));
        }
        return num_stack.empty() ? 0 : num_stack.top();
    }
    int eval(int num1, int num0, char op) {
        cout << "test " << num1 << " " << op << " " << num0 << endl;
        int ans = 0;
        switch (op) {
        case '+':
            ans = num0 + num1;
            break;
        case '-':
            ans = num0 - num1;
            break;
        case '*':
            ans = num0 * num1;
            break;
        case '/':
            ans = num0 / num1;
            break;
        }
        return ans;
    }
};

int main() {
	// your code goes here
    Solution s;
    std::vector<string> expression;
    //["2","*","6","-","(","23","+","7",")","/","(","1","+","2",")"]
    expression.push_back(string("2"));
    expression.push_back(string("*"));
    expression.push_back(string("6"));
    expression.push_back(string("-"));
    expression.push_back(string("("));
    expression.push_back(string("23"));
    expression.push_back(string("+"));
    expression.push_back(string("7"));
    expression.push_back(string(")"));
    expression.push_back(string("/"));
    expression.push_back(string("("));
    expression.push_back(string("1"));
    expression.push_back(string("+"));
    expression.push_back(string("2"));
    expression.push_back(string(")"));
    cout << s.evaluateExpression(expression) << endl;
	return 0;
}
