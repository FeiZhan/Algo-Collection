//Memory Limit Exceeded
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<bool> > valid_pare;
		vector<vector<int> > pare_left;
		vector<vector<int> > pare_right;
		for (int i = 0; i < s.length(); ++ i)
		{
			valid_pare.push_back(vector<bool>(s.length()));
			pare_left.push_back(vector<int>(s.length()));
			pare_right.push_back(vector<int>(s.length()));
		}
		int longest = 0;
		for (int i = 0; i < s.length(); ++ i)
		{
			for (int j = i; j < s.length(); ++ j)
			{
				if (j == i)
				{
					valid_pare[i][j] = false;
					if ('(' == s[j])
					{
						pare_left[i][j] = 1;
						pare_right[i][j] = 0;
					} else
					{
						pare_left[i][j] = 0;
						pare_right[i][j] = 1;
					}
				} else if ('(' == s[j])
				{
					valid_pare[i][j] = false;
					pare_left[i][j] = pare_left[i][j - 1] + 1;
					pare_right[i][j] = pare_right[i][j - 1];
				} else if (')' == s[j])
				{
					if (pare_left[i][j - 1] > 0)
					{
						pare_left[i][j] = pare_left[i][j - 1] - 1;
						pare_right[i][j] = pare_right[i][j - 1];
					} else
					{
						pare_left[i][j] = pare_left[i][j - 1];
						pare_right[i][j] = pare_right[i][j - 1] + 1;
					}
					valid_pare[i][j] = (0 == pare_left[i][j] && 0 == pare_right[i][j]);
					if (valid_pare[i][j] && longest < j - i + 1)
					{
						longest = j - i + 1;
					}
				}
			}
		}
		return longest;
    }
};
