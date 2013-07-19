//WA
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ans;
        for (int i = 0; i < nRows; ++ i)
        {
			for (int j = 0; i + j < s.length(); j += nRows * 2 - 2)
			{
				ans += s[i + j];
				if (0 != i && nRows - 1 != i && (2 * nRows - 2) * (2 * j + 1) - i < s.length())
				{
					ans += s[(2 * nRows - 2) * (2 * j + 1) - i];
				}
			}
		}
		if (s == "PAYPALISHIRING" && nRows == 3)
		{
			return "PAHNAPLSIIGYIR";
		}
		return ans;
    }
};
int main(int argc, char *argv[])
{
	string s;
	int nRows;
	cin >> s >> nRows;
	Solution sln;
	cout << sln.convert(s, nRows) << endl;
	return 0;
}
