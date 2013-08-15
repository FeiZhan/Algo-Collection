class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lastspace = -1, lastspace2 = -1, length = strlen(s);
        bool consec = false;
        for (int i = 0; i < length; ++ i)
        {
			if (' ' == s[i])
			{
				if (! consec)
				{
					consec = true;
					lastspace2 = lastspace;
					lastspace = i;
				} else
				{
					lastspace2 = i;
				}
			} else
			{
				consec = false;
			}
		}
		if (0 == length)
		{
			return 0;
		} else if (-1 == lastspace)
		{
			if (consec)
			{
				return 0;
			} else
			{
				return length;
			}
		} else if (' ' == s[length - 1])
		{
			if (-1 == lastspace2)
			{
				return lastspace;
			} else
				return lastspace - lastspace2 - 1;
		} else
		{
			return length - 1 - lastspace;
		}
    }
};
