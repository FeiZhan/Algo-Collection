class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::string> ans;
		if (n == 0)
		{
			return ans;
		} else if (1 == n)
		{
			ans.push_back(std::string("()"));
			return ans;
		} else
		{
			std::set<std::string> ans_set;
			std::vector<std::string> last( generateParenthesis(n - 1) );
			for (int i = 0; i < n; ++ i)
			{
				for (int j = 0; j < last.size(); ++ j)
				{
					std::string tmp( "(" + last[j] );
					tmp.insert(1 + i * 2, ")");
					ans_set.insert(tmp);
				}
			}
			// may have duplicates
			for (std::set<std::string>::iterator it = ans_set.begin(); it != ans_set.end(); ++ it)
			{
				ans.push_back(*it);
			}
		}
		return ans;
    }
};

// copied from leetcode discussion, not fully understand. Why no duplicates?
vector<string> generateParenthesis(int n)
{
	vector<string> ans;
	if (n > 0)
	{
		generate(ans, "", 0, 0, n);
	}
	return ans;
}
void generate(vector<string> &ans, string s, int l, int r, int n)
{
	if (l == n)
	{
		ans.push_back(s.append(n - r, ')'));
		return;
	}
	generate(ans, s + '(', l + 1, r, n);
	if (l > r)
	{
		generate(ans, s + ")", l, r + 1, n);
	}
}
