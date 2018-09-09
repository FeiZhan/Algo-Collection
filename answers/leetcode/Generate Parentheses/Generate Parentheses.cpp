//@result 8 / 8 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 11.31% of cpp submissions

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		string paren;
		generateParenthesis(n, 0, 0, paren);
		return ans;
    }
    void generateParenthesis(int n, int left, int right, const string &paren)
    {
		if (left == n && right == n)
		{
			ans.push_back(paren);
			return;
		}
		if (left < n)
		{
			string temp(paren + string("("));
			generateParenthesis(n, left + 1, right, temp);
		}
		if (left > right)
		{
			string temp(paren + string(")"));
			generateParenthesis(n, left, right + 1, temp);
		}
	}
    vector<string> ans;
};
