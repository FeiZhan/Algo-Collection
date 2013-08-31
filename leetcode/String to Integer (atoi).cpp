// copied from leetcode
class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (NULL == str || '\0' == *str)
		{
			return 0;
		}
		const char *p = str;
		int minus = 1;
		while (' ' == *p)
		{
			++ p;
		}
		if ('-' == *p)
		{
			minus = -1;
			++ p;
		} else if ('+' == *p)
		{
			minus = 1;
			++ p;
		}
		int num = 0;
		while ( isdigit(*p) )
		{
			if ( (214748364 == num && static_cast<int>(*p - '0') > 7) || num > 214748364 )
			{
				return minus > 0 ? INT_MAX : INT_MIN;
			}
			num = 10 * num + static_cast<int>(*p - '0');
			++ p;
		}
		return minus > 0 ? num : - num;
    }
};
