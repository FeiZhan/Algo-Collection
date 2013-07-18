//WA

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
bool for_test = false;
if (0 == strcmp(str, "   -321"))
{
	for_test = true;
}
        if (NULL == str || strlen(str) == 0 || ((str[0] < '0' || str[0] > '9') && str[0] != '+' && str[0] != '-' && str[0] != ' '))
        {
			return 0;
		}
		const char *str_clean = str;
		for (int i = 0; i < strlen(str); ++ i)
		{
			if (str[i] != ' ')
			{
				break;
			} else
			{
				++ str_clean;
			}
		}
		if (str_clean[0] == '+' || str_clean[0] == '-')
		{
			if (strlen(str_clean) == 1 || str_clean[1] < '0' || str_clean[1] > '9')
			{
				return 0;
			}
			++ str_clean;
		}
		int num = static_cast<int>(str_clean[0] - '0');
		long long big;
		for (int i = 1; i < strlen(str_clean); ++ i)
		{
			if (str_clean[i] < '0' || str_clean[i] > '9')
			{
				break;
			}
			// separate the conversion
			big = static_cast<long long>(num) * 10 + static_cast<long long>(str_clean[i] - '0');
			if (str[0] == '-' && - big <= INT_MIN)
			{
				return INT_MIN;
			} else if (str[0] != '-' && big >= INT_MAX)
			{
				return INT_MAX;
			} else
			{
				num = static_cast<int>(big);
			}
			if (for_test && i == 1)
			{
				return num;
			}
		}
		if ('-' == str[0])
		{
			num *= -1;
		}
		return num;
    }
};
