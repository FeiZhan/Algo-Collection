class Solution {
public:
	void reverseWords(string &s) {
		size_t len = s.length();
		if (0 == len)
		{
			return;
		}
		for (size_t i = 0, j = 0; i <= len; ++i)
		{
			if (s.length() == i || ' ' == s[i] || '\t' == s[i] || '\n' == s[i] || '\r' == s[i])
			{
				if (i > j)
				{
					s += s.substr(j, i) + std::string(" ");
				}
				j = i;
			}
		}
		s = s.substr(len, s.length() - 1);
	}
};