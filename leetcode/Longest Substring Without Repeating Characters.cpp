//WA

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0)
        {
			return 0;
		}
        int begin = 0, max = 1;
        for (int i = 1; i < s.length(); ++ i)
        {
			if (max > i - begin)
			{
				continue;
			}
			string target = s.substr(begin, i - begin);
			unsigned pos = target.find(s[i]);
			if (pos == string::npos)
			{
				if (i - begin + 1 > max)
				{
					max = i - begin + 1;
				}
			} else
			{
				begin += pos;
			}
		}
		return max;
    }
};
