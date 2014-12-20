class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		std::stack<int> token_stack;
		for (size_t i = 0; i < tokens.size(); ++ i) {
			if (string("+") == tokens[i] || string("-") == tokens[i] || string("*") == tokens[i] || string("/") == tokens[i]) {
				if (token_stack.empty()) {
					break;
				}
				int op0 = token_stack.top();
				token_stack.pop();
				if (token_stack.empty()) {
					break;
				}
				int op1 = token_stack.top();
				token_stack.pop();
				int ans = 0;
				switch (tokens[i][0]) {
				case '+':
					//@note the order of numbers
					ans = op1 + op0;
					break;
				case '-':
					ans = op1 - op0;
					break;
				case '*':
					ans = op1 * op0;
					break;
				case '/':
					if (0 != op0) {
						ans = op1 / op0;
					}
					break;
				}
				token_stack.push(ans);
			} else {
				token_stack.push(atoi(tokens[i].c_str()));
			}
		}
		if (token_stack.empty()) {
			return 0;
		}
		return token_stack.top();
    }
};
