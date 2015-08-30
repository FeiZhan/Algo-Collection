class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == s.length())
        {
			return 0;
		}
        vector<vector<int> > ways;
        for (int i = 0; i < s.length(); ++ i)
        {
			ways.push_back(vector<int>(s.length()));
		}
        for (int i = 0; i < s.length(); ++ i)
        {
			for (int j = 0; i + j < s.length(); ++ j)
			{
				if (0 == j)
				{
					if ('0' == s[i])
					{
						ways[i][j] = 0;
					} else
					{
						ways[i][j] = 1;
					}
				} else if (1 == j)
				{
					if (('0' == s[i + j - 1] || '2' < s[i + j - 1]) && '0' == s[i + 1])
					{
						ways[i][j] = 0;
					} else if ('2' < s[i] || ('2' == s[i] && '6' < s[i + 1]) || '0' == s[i] || '0' == s[i + 1])
					{
						ways[i][j] = ways[i][j - 1];
					} else
					{
						ways[i][j] = 2;
					}
				} else
				{
					// problems with 0
					if ('0' == s[i + j])
					{
						if ('0' == s[i + j - 1] || '2' < s[i + j - 1])
						{
							ways[i][j] = 0;
						} else
						{
							ways[i][j] = ways[i][j - 2];
						}
					} else if ('2' < s[i + j - 1] || ('2' == s[i + j - 1] && '6' < s[i + j]) || '0' == s[i + j - 1])
					{
						ways[i][j] = ways[i][j - 1];
					} else
					{
						ways[i][j] = ways[i][j - 2] + ways[i][j - 1];
					}
				}
			}
		}
		return ways[0][s.length() - 1];
    }
};

// 2014-12-24
class Solution {
public:
	int numDecodings(string s) {
		if (0 == s.length()) {
			return 0;
		}
		std::vector<int> dp(s.length(), 0);
		dp[0] = s[0] > '0';
		for (size_t i = 1; i < s.length(); ++ i) {
			if ((s[i - 1] == '1' && s[i] > '0') || ('2' == s[i - 1] && s[i] > '0' && s[i] <= '6')) {
				if (i >= 2) {
					dp[i] = dp[i - 2] + dp[i - 1];
				} else {
					dp[i] = dp[i - 1] + 1;
				}
			}
			else if ('0' == s[i]) {
				if (s[i - 1] >= '1' && s[i - 1] <= '2') {
					if (i >= 2) {
						dp[i] = dp[i - 2];
					} else {
						dp[i] = 1;
					}
				} else {
					dp[i] = 0;
				}
			}
			else {
				dp[i] = dp[i - 1];
			}
		}
		return dp[s.length() - 1];
	}
};
