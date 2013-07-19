#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string palin;
        if (s.length() == 0)
        {
			return palin;
		} else
		{
			palin = s.substr(0, 1);
		}
        for (int i = 0; i < s.length(); ++ i)
        {
			for (int j = i + palin.length(); j < s.length(); ++ j)
			{
				if (s[j] != s[i] || j - i + 1 <= palin.length())
				{
					continue;
				}
				bool flag = true;
				for (int k = 1; k <= (j - i) / 2; ++ k)
				{
					if (s[i + k] != s[j - k])
					{
						flag = false;
						break;
					}
				}
				if (flag && j - i + 1 > palin.length())
				{
					palin = s.substr(i, j - i + 1);
				}
			}
		}
		return palin;
    }
};

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	Solution sln;
	cout << sln.longestPalindrome(s) << endl;
	return 0;
}
