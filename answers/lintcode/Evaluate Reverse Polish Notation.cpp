class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<int> num_stack;
        for (size_t i = 0; i < tokens.size(); ++ i) {
            if ("+" == tokens[i] || "-" == tokens[i] || "*" == tokens[i] || "/" == tokens[i]) {
                int num0 = num_stack.top();
                num_stack.pop();
                int num1 = num_stack.top();
                num_stack.pop();
                num_stack.push(eval(num1, num0, tokens[i][0]));
            }
            else {
                num_stack.push(stoi(tokens[i]));
            }
        }
        return num_stack.top();
    }
    int eval(int num0, int num1, char op) {
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
