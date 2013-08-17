class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = strlen(s);
        // a virtual space behind the string
        int end = length;
        for (int i = length - 1; i >= 0; -- i)
        {
			if (' ' != s[i])
			{
				break;
			} else
			{
				end = i;
			}
		}
        // a virtual space before the string
		int begin = -1;
		for (int i = 0; i < end; ++ i)
		{
			if (' ' == s[i])
			{
				begin = i;
			}
		}
        // distance between two spaces minus one
		return end - begin - 1;
    }
};
