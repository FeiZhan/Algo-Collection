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

// 2015-1-1
//@result 22 / 22 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 10.23% of cpp submissions.
class Solution {
public:
	void reverseWords(string &s) {
		string reversed;
		int begin = -1;
		for (int i = 0; i <= s.length(); ++ i) {
			if (s.length() == i || ' ' == s[i] || '\t' == s[i] || '\n' == s[i] || '\r' == s[i]) {
				if (i > begin + 1) {
					reversed = s.substr(begin + 1, i - begin - 1) + " " + reversed;
				}
				begin = i;
			}
		}
		s = reversed.substr(0, reversed.length() - 1);
	}
};
