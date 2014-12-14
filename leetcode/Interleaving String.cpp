#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
		if (s1.length() + s2.length() != s3.length())
		{
			return false;
		}
		if (s3.length() == 0)
		{
			return true;
		}
		vector<vector<bool> > ans;
		for (int i = 0; i <= s1.length(); ++ i)
		{
			// larger size
			vector<bool> tmp(s3.length() + 1);
			ans.push_back(tmp);
		}
		for (int i = 0; i <= s1.length(); ++ i)
		{
			for (int j = 0; i + j <= s3.length(); ++ j)
			{
				if (0 == i && 0 == j)
				{
					ans[0][0] = true;
				} else if (0 == i)
				{
					ans[i][j] = ans[i][j - 1] && s2[j - 1] == s3[i + j - 1]; //(s2.substr(0, j) == s3.substr(0, j));
				} else if (0 == j)
				{
					ans[i][j] = ans[i - 1][j] && s1[i - 1] == s3[i + j - 1]; //(s1.substr(0, i) == s3.substr(0, i));
				} else
				{
					ans[i][j] = (ans[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (ans[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
				}
				if (i + j == s3.length())
				{
					if (ans[i][j])
					{
						return true;
					}
				}
			}
		}
		return false;
    }
};
int main(int argc, char *argv[])
{
	Solution s;
	//"aa", "ab", "aaba"
	cout << s.isInterleave(string("aa"), string("ab"), string("aaba")) << endl;
	//"abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb", "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc", "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc"
	cout << s.isInterleave(string("abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb"), string("ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc"), string("cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc")) << endl;
	return 0;
}

// 2014-12-14
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length()) {
			return false;
		}
		if (0 == s1.length()) {
			return s2 == s3;
		}
		if (0 == s2.length()) {
			return s1 == s3;
		}
		std::vector<std::vector<bool> > dp(s1.length() + 1, std::vector<bool> (s2.length() + 1, false));
		dp[0][0] = true;
		for (size_t i = 1; i <= s1.length(); ++ i) {
			dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
		}
		for (size_t i = 1; i <= s2.length(); ++ i) {
			dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
		}
		for (size_t i = 1; i <= s1.length(); ++ i) {
			for (size_t j = 1; j <= s2.length(); ++ j) {
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 0; j < dp[i].size(); ++ j) {
				//std::cout << i << " " << j << " : " << dp[i][j] << " " << s1[i - 1] << " " << s2[j - 1] << " + " << s3[i + j - 2] << endl;
			}
		}
		return dp[s1.length()][s2.length()];
    }
};
