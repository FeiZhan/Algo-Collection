#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<string> > ans;
		std::vector<std::vector<bool> > palin;
		for (int i = 0; i < s.length(); ++ i)
		{
			palin.push_back(std::vector<bool>(s.length()));
		}
		for (int i = 0; i < s.length(); ++ i)
		{
			// odd
			palin[i][i] = true;
			for (int j = 1; i - j >= 0 && i + j < s.length(); ++ j)
			{
				palin[i - j][i + j] = palin[i - j + 1][i + j - 1] && s[i - j] == s[i + j];
			}
			// even
			for (int j = 0; i - j >= 0 && i + j + 1 < s.length(); ++ j)
			{
				palin[i - j][i + j + 1] = (0 == j || palin[i - j + 1][i + j]) && s[i - j] == s[i + j + 1];
			}
		}
		getPalin(s, 0, vector<string>(), ans, palin);
		return ans;
    }
	void getPalin(const std::string &s, const int begin, const std::vector<std::string> &past, std::vector<std::vector<std::string> > &ans, const std::vector<std::vector<bool> > &palin)
	{
		if (begin == s.length())
		{
			ans.push_back(past);
			return;
		}
		if (begin > s.length())
		{
			return;
		}
		for (int i = begin; i < s.length(); ++ i)
		{
			if (palin[begin][i])
			{
				std::vector<std::string> now = past;
				now.push_back(s.substr(begin, i - begin + 1));
				getPalin(s, i + 1, now, ans, palin);
			}
		}
	}
};
int main()
{
	Solution s;
	vector<vector<string> > ans;
	ans = s.partition("cdd");
	for (int i = 0; i < ans.size(); ++ i)
	{
		for (int j = 0; j < ans[i].size(); ++ j)
		{
			std::cout << ans[i][j] << "+";
		}
		std::cout << ", ";
	}
	std::cout << std::endl;
	return 0;
}
