#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<std::string> ans;
		if (0 == L)
		{
			ans.push_back(std::string(""));
			return ans;
		}
		int begin = 0, len = -1;
		for (int i = 0; i < words.size(); ++ i)
		{
			if (i == words.size() || len + words[i].length() + 1 > L)
			{
				int spaces = (i - 1 - begin > 0) ? (L - len) / (i - 1 - begin) : 0;
				std::string tmp;
				for (int j = begin; j < i; ++ j)
				{
					tmp.append(words[j]);
					if (j + 1 < i)
					{
						tmp.append(std::string(spaces + 1, ' '));
					}
				}
				if (tmp.size() < L)
				{
					tmp.append(std::string(L - tmp.size(), ' '));
				}
				ans.push_back(tmp);
				begin = i;
				if (i < words.size())
				{
					len = words[i].length();
				}
			} else
			{
				len += words[i].length() + 1;
			}
		}
		if (begin + 1 < words.size())
		{
			std::string tmp;
			for (int j = begin; j < words.size(); ++ j)
			{
				tmp.append(words[j]);
				if (j + 1 < words.size())
				{
					tmp.append(std::string(1, ' '));
				}
			}
			if (tmp.size() < L)
			{
				tmp.append(std::string(L - tmp.size(), ' '));
			}
			ans.push_back(tmp);
		}
		if (0 == ans.size())
		{
			ans.push_back(std::string(" ", L));
		}
		return ans;
    }
};
int main()
{
	Solution s;
	std::vector<std::string> words;
	words.push_back(std::string(""));
	std::vector<std::string> ans = s.fullJustify(words, 2);
	for (int i = 0; i < ans.size(); ++ i)
	{
		std::cout << "\"" << ans[i] << "\"" << std::endl;
	}
	return 0;
}
