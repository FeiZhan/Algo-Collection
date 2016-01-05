//@result 117 / 117 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 43.29% of cpp submissions.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == strs.size())
        {
			return std::string();
		}
		int i;
		bool flag = true;
        for (i = 0; i < strs[0].length(); ++ i)
        {
			for (int j = 1; j < strs.size(); ++ j)
			{
				if (strs[j].length() <= i || strs[0][i] != strs[j][i])
				{
					flag = false;
					break;
				}
			}
			if (! flag)
			{
				break;
			}
		}
		return strs[0].substr(0, i);
    }
};

int main()
{
	Solution s;
	vector<string> strs;
	//["babb","caa"]
	strs.push_back(std::string("babb"));
	strs.push_back(std::string("caa"));
	std::cout << s.longestCommonPrefix(strs) << std::endl;
	return 0;
}
