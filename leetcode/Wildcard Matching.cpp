class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (! *s == ! *p)
		{
			return true;
		}
		int ssize = 1;
		const char *tmp = s;
		while (*tmp)
		{
			++ ssize;
			++ tmp;
		}
		int psize = 1;
		tmp = p;
		while (*tmp)
		{
			++ psize;
			++ tmp;
		}
		if (ssize < psize)
		{
			return false;
		}
		std::vector<std::vector<bool> > match_mat(2, std::vector<bool>(ssize, false));
		bool flag = true;
		match_mat[0][0] = true;
		do
		{
			if (*p == '*')
			{
				
			}
		} while ();
    }
};
// 2014-04-17, wrong answer
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (NULL == p)
		{
			return s == p;
		}
		if (strlen(p) == 0)
		{
			return 0 == strlen(s);
		}
		int temp = 0;
		switch (p[0])
		{
		case '?':
			return isMatch(s + 1, p + 1);
			break;
		case '*':
			while (temp <= strlen(p) && *(p + temp) == '*')
			{
				++temp;
			}
			for (size_t i = 0; i < strlen(s); ++i)
			{
				if (isMatch(s + i, p + temp))
				{
					return true;
				}
			}
			return false;
			break;
		default:
			return s[0] == p[0] && isMatch(s + 1, p + 1);
			break;
		}
	}
};