// copied from leetcode discussion
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int maxLen = 0, last = -1;
		std::stack<int> lefts;
		for (int i = 0; i < s.length(); ++ i)
		{
			if ('(' == s[i])
			{
				lefts.push(i);
			} else
			{
				if (lefts.empty())
				{
					last = i;
				} else
				{
					lefts.pop();
					int tmp = lefts.empty() ? i - last : i - lefts.top();
					if (maxLen < tmp)
					{
						maxLen = tmp;
					}
				}
			}
		}
		return maxLen;
    }
};
