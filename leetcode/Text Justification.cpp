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
					if (i - 1 - begin > 0 && (L - len) % (i - 1 - begin) > j - begin)
					{
						tmp.append(std::string(1, ' '));
					}
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
		if (begin < words.size())
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
			ans.push_back(std::string(L, ' '));
		}
		return ans;
    }
    void Output(const std::vector<std::string> &ans)
    {
		for (int i = 0; i < ans.size(); ++ i)
		{
			std::cout << "\"" << ans[i] << "\"" << std::endl;
		}
	}
};
int main()
{
	Solution s;
	std::vector<std::string> words;
	//["Here","is","an","example","of","text","justification."], 16

	words.push_back(std::string("Here"));
	words.push_back(std::string("is"));
	words.push_back(std::string("an"));
	words.push_back(std::string("example"));
	words.push_back(std::string("of"));
	words.push_back(std::string("text"));
	words.push_back(std::string("justification"));
	std::vector<std::string> ans = s.fullJustify(words, 16);

	//["a","b","c","d","e"], 1
/*
	words.push_back(std::string("a"));
	words.push_back(std::string("b"));
	words.push_back(std::string("c"));
	words.push_back(std::string("d"));
	std::vector<std::string> ans = s.fullJustify(words, 1);
*/
	//["Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."], 30	["Don't  go  around  saying  the","world  owes you a living; the ","world owes you nothing; it was","here first.                   "]	["Don't  go  around  saying  the","world  owes  you a living; the","world owes you nothing; it was","here first.                   "]	
  

	cout << "result ";
	s.Output(ans);
	return 0;
}
