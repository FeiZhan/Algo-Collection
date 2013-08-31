class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int max = 0;
		// begin
		int i = 0;
		// end
		int j = 0;
		bool exist[256] = {false};
		while (j < s.length())
		{
			if (exist[s[j]])
			{
				max = std::max(max, j - i);
				// remove same char
				while (s[i] != s[j])
				{
					exist[s[i]] = false;
					++ i;
				}
				++ i;
				++ j;
			} else
			{
				exist[s[j]] = true;
				++ j;
			}
		}
		max = std::max(max, static_cast<int>( s.length() ) - i);
		return max;
    }
};
