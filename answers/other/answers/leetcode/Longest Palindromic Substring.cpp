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

// 2014-12-14
class Solution {
public:
    string longestPalindrome(string s) {
		// don't use vector<vector>
        bool dp[1010][1010] = {false};
        bool same_flag = true;
        int max_len = 0;
        int start = 0;
        for (int i = 0; i < s.length(); ++ i) {
            dp[0][i] = true;
        }
        for (int i = 0; i + 1 < s.length(); ++ i) {
            if (s[i] == s[i + 1]) {
                dp[1][i] = true;
                max_len = 1;
                start = i;
            }
        }
        for (int i = 2; i < s.length(); ++ i) {
            for (int j = 0; i + j < s.length(); ++ j) {
                if (dp[i - 2][j + 1] && s[j] == s[j + i]) {
                    dp[i][j] = true;
                    max_len = i;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len + 1);
    }
};
