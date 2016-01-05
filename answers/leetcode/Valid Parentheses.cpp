//@result 65 / 65 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 5.29% of cpp submissions.

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		stack<char> Par_stack;
		for (int i = 0; i < s.length(); ++ i)
		{
			switch(s[i])
			{
			case '(':
			case '[':
			case '{':
				Par_stack.push(s[i]);
				break;
			case ')':
				if (! Par_stack.empty() && '(' == Par_stack.top())
				{
					Par_stack.pop();
				} else
				{
					return false;
				}
				break;
			case ']':
				if (! Par_stack.empty() && '[' == Par_stack.top())
				{
					Par_stack.pop();
				} else
				{
					return false;
				}
				break;
			case '}':
				if (! Par_stack.empty() && '{' == Par_stack.top())
				{
					Par_stack.pop();
				} else
				{
					return false;
				}
				break;
			}
		}
		return Par_stack.empty();
    }
};
