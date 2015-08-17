#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ("0" == num1 || "0" == num2)
        {
			return string("0");
		}
        string ans;
		for (int i = num1.length() - 1; i >= 0; -- i)
		{
			string tmp(num2.length(), '0');
			int mul = static_cast<int>(num1[i] - '0');
			int carry = 0;
			for (int j = num2.length() - 1; j >= 0; -- j)
			{
				int multiply = mul * static_cast<int>(num2[j] - '0') + carry;
				carry = multiply / 10;
				tmp[j] = static_cast<char>('0' + multiply % 10);
			}
			while (carry)
			{
				tmp.insert(0, 1, static_cast<char>('0' + carry % 10));
				carry = carry / 10;
			}
			tmp = tmp + string(num1.length() - 1 - i, '0');
			carry = 0;
			for (int j = 0; j < ans.length(); ++ j)
			{
				int digit = static_cast<int>(ans[ans.length() - 1 - j] - '0') + carry;
				if (tmp.length() > j)
				{
					digit += static_cast<int>(tmp[tmp.length() - 1 - j] - '0');
				}
				ans[ans.length() - 1 - j] = static_cast<char>('0' + digit % 10);
				carry = digit / 10;
			}
			for (int j = ans.length(); j < tmp.length(); ++ j)
			{
				int digit = static_cast<int>(tmp[tmp.length() - 1 - j] - '0') + carry;
				ans.insert(0, 1, static_cast<char>('0' + digit % 10));
				carry = digit / 10;
			}
			while (carry)
			{
				ans.insert(0, 1, static_cast<char>('0' + carry % 10));
				carry = carry / 10;
			}
		}
		// does not work, i don't know why
		if (ans.length() > 0 && 0 == ans[0])
		{
			int i;
			for (i = 0; i < ans.length(); ++ i)
			{
				if (0 != ans[i])
				{
					break;
				}
			}
			ans.erase(0, i);
		}
		return ans;
    }
};
int main()
{
	Solution s;
	cout << s.multiply("1", "1") << endl;
	return 0;
}
