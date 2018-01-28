//@result 476 / 476 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 42.69% of cpp submissions.

class Solution {
public:
	bool isPalindrome(string s) {
		for (size_t i = 0, j = s.length() - 1; i < s.length() && j < s.length() && i <= j; ++i, --j)
		{
			while (i < s.length() && !isAlphanumeric(s[i]))
			{
				++i;
			}
			while (j < s.length() && !isAlphanumeric(s[j]))
			{
				--j;
			}
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
            }
            if (s[j] >= 'A' && s[j] <= 'Z') {
                s[j] += 'a' - 'A';
            }
			//std::cout << i << " " << s[i] << " " << char(s[i] - 'a' + 'A') << std::endl;
			//std::cout << j << " " << s[j] << " " << char(s[j] - 'a' + 'A') << std::endl;
			if (i < s.length() && j < s.length() && s[i] != s[j])
			{
				return false;
			}
		}
		return true;
	}
	bool isAlphanumeric(char c)
	{
		return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
	}
};
