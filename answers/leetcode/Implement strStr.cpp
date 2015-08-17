class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == needle || strlen(needle) == 0)
        {
			return haystack;
		}
		if (NULL == haystack)
		{
			return NULL;
		}
		for (int i = 0; i < strlen(haystack); ++ i)
		{
			// just compare the lengths directly
			if (strlen(haystack) - i < strlen(needle))
			{
				break;
			}
			if (haystack[i] == needle[0])
			{
				bool flag = false;
				for (int j = 0; j < strlen(needle); ++ j)
				{
					if (haystack[i + j] != needle[j])
					{
						flag = true;
						break;
					}
				}
				if (false == flag)
				{
					return haystack + i;
				}
			}
		}
		return NULL;
    }
};
