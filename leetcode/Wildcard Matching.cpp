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
