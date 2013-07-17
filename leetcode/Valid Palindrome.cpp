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
