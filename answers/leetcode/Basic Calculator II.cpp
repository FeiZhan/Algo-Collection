//@type String
//@result 109 / 109 test cases passed. Status: Accepted Runtime: 92 ms Submitted: 0 minutes ago You are here! Your runtime beats 11.62% of cpp submissions.

class Solution {
public:
	int calculate(string s) {
		stack<char> op_stack;
		stack<int> num_stack;
		vector<char> op_list;
		for (size_t i = 0; i < s.length(); ++ i) {
			switch (s[i]) {
			case ' ':
			case '\0':
			case '\t':
			case '\n':
				break;
			case '*':
			case '/':
				while (! op_stack.empty() && ('*' == op_stack.top() || '/' == op_stack.top())) {
					int num0 = num_stack.top();
					num_stack.pop();
					int num1 = num_stack.top();
					num_stack.pop();
					num_stack.push(cal(op_stack.top(), num1, num0));
					op_stack.pop();
				}
				op_stack.push(s[i]);
				break;
			case '+':
			case '-':
				while (! op_stack.empty() && ('*' == op_stack.top() || '/' == op_stack.top() || '+' == op_stack.top() || '-' == op_stack.top())) {
					int num0 = num_stack.top();
					num_stack.pop();
					int num1 = num_stack.top();
					num_stack.pop();
					num_stack.push(cal(op_stack.top(), num1, num0));
					op_stack.pop();
				}
				op_stack.push(s[i]);
				break;
			case '(':
				op_stack.push(s[i]);
				break;
			case ')':
				while (! op_stack.empty() && '(' != op_stack.top()) {
					int num0 = num_stack.top();
					num_stack.pop();
					int num1 = num_stack.top();
					num_stack.pop();
					num_stack.push(cal(op_stack.top(), num1, num0));
					op_stack.pop();
				}
				op_stack.pop();
				break;
			default:
				int num(0);
				while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 + static_cast<int> (s[i] - '0');
					++ i;
				}
				-- i;
				num_stack.push(num);
				break;
			}
		}
		while (! op_stack.empty()) {
			int num0 = num_stack.top();
			num_stack.pop();
			int num1 = num_stack.top();
			num_stack.pop();
			num_stack.push(cal(op_stack.top(), num1, num0));
			op_stack.pop();
		}
		return num_stack.empty() ? 0 : num_stack.top();
	}
	int cal(char op, int num0, int num1) {
		switch (op) {
		case '+':
			num0 += num1;
			break;
		case '-':
			num0 -= num1;
			break;
		case '*':
			num0 *= num1;
			break;
		case '/':
			num0 /= num1;
			break;
		}
		return num0;
	}
};