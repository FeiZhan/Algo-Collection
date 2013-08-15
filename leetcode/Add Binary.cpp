#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string sum;
		for (int i = 0; i < a.length(); ++ i)
		{
			if (b.length() > i)
			{
				string tmp = a.substr(a.length() - 1 - i, 1);
				tmp[0] += static_cast<int>(b[b.length() - 1 - i] - '0');
				sum = tmp + sum;
			} else
			{
				sum = a.substr(a.length() - 1 - i, 1) + sum;
			}
		}
		for (int i = a.length(); i < b.length(); ++ i)
		{
			sum = b.substr(b.length() - 1 - i, 1) + sum;
		}
		int carry = 0;
		for (int i = sum.length() - 1; i >= 0; -- i)
		{
			sum[i] += carry;
			if (sum[i] >= '2')
			{
				carry = (sum[i] - '0') / 2;
				sum[i] = ((sum[i] - '0') % 2) + '0';
			} else
			{
				carry = 0;
			}
		}
		while (carry)
		{
			string tmp("0");
			tmp[0] += carry % 2;
			carry /= 2;
			sum = tmp + sum;
		}
		return sum;
    }
};
int main(int argc, char *argv[])
{
	Solution s;
	cout << s.addBinary("11", "1") << endl;
	return 0;
}
