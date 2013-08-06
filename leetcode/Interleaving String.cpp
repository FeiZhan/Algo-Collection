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
