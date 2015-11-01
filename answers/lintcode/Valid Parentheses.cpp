class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
		stack<char> parent_stack;
		for (size_t i = 0; i < s.length(); ++ i) {
			switch (s[i]) {
			case '(':
			case '[':
			case '{':
				parent_stack.push(s[i]);
				break;
			case ')':
				if (! parent_stack.empty() && '(' == parent_stack.top()) {
					parent_stack.pop();
				}
				else {
					return false;
				}
				break;
			case ']':
				if (! parent_stack.empty() && '[' == parent_stack.top()) {
					parent_stack.pop();
				}
				else {
					return false;
				}
				break;
			case '}':
				if (! parent_stack.empty() && '{' == parent_stack.top()) {
					parent_stack.pop();
				}
				else {
					return false;
				}
				break;
			}
		}
		return parent_stack.empty();
    }
};
