//WA

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::string ans;
		std::vector<int> factor;
		std::vector<bool> flag(n + 1, false);
		factor.push_back(1);
		for (int i = 1, num = 1; i <= n + 1 || num <= k + 1; num *= ++ i)
		{
			factor.push_back(num);
		}
		for (int i = factor.size() - 2; i > 0; -- i)
		{
			if (factor[i] < k && factor[i + 1] >= k && k / factor[i] + 1 <= n)
			{
				ans += static_cast<char>(k / factor[i] + '1');
std::cout << "test2 " << k << " " << factor[i] << " " << (k / factor[i] + 1) << std::endl;
				flag[k / factor[i] + 1] = true;
				k %= factor[i];
			} else if (factor[i] == k && ! flag[2])
			{
				ans += '2';
				flag[2] = true;
			}
		}
		if (ans.length() < n)
		{
			for (size_t i = 1; i < flag.size(); ++ i)
			{
				if (false == flag[i])
				{
					ans += static_cast<char>(i + '0');
				}
			}
		}
		return ans;
    }
};
int main()
{
	Solution s;
	std::cout << s.getPermutation(2, 1) << std::endl;
	return 0;
}
