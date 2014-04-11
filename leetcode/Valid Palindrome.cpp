class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < s.length(); ++ i)
        {
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] += 'a' - 'A';
			} else if (s[i] >= '0' && s[i] <= '9')
			{
				continue;
			} else if (s[i] < 'a' || s[i] > 'z')
			{
				s.erase(i, 1);
				-- i;
			}
		}
		bool flag = true;
		for (int i = 0; i < s.length() / 2; ++ i)
		{
			if (s[i] != s[s.length() - 1 - i])
			{
				flag = false;
				break;
			}
		}
		return flag;
    }
};
// accepted 2014-03-21
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
			//std::cout << i << " " << s[i] << " " << isAlphanumeric(s[i]) << std::endl;
			//std::cout << j << " " << s[j] << " " << isAlphanumeric(s[j]) << std::endl;
			if (i < s.length() && j < s.length() && s[i] != s[j] && s[i] != s[j] - 'a' + 'A' && s[i] - 'a' + 'A' != s[j])
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