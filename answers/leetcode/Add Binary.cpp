// 2014-04-20 AC
//@result 294 / 294 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 20.86% of cpp submissions.

class Solution {
public:
    string addBinary(string a, string b) {
		string ans;
		int carry = 0;
		size_t i;
		for (i = 0; i < a.length() && i < b.length(); ++ i)
		{
			int sum = (a[a.length() - 1 - i] - '0') + (b[b.length() - 1 - i] - '0') + carry;
			carry = sum / 2;
			sum %= 2;
			ans += static_cast<char>(sum + '0');
		}
		for (; i < a.length(); ++ i)
		{
			int sum = (a[a.length() - 1 - i] - '0') + carry;
			carry = sum / 2;
			sum %= 2;
			ans += static_cast<char>(sum + '0');
		}
		for (; i < b.length(); ++ i)
		{
			int sum = (b[b.length() - 1 - i] - '0') + carry;
			carry = sum / 2;
			sum %= 2;
			ans += static_cast<char>(sum + '0');
		}
		while (carry)
		{
			int sum = carry;
			carry = sum / 2;
			sum %= 2;
			ans += static_cast<char>(sum + '0');
		}
		std::reverse(ans.begin(), ans.end());
		return ans;
    }
};
