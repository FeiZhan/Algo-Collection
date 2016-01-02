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

// 2014-12-09
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        size_t begin = 0, end = 0;
        // using std::map is too slow
        bool char_map[1024] = {false};
        while (begin < s.length() && end < s.length()) {
        	if (char_map[static_cast<size_t>(s[end])]) {
        		if (end - begin > max) {
        			max = end - begin;
        			//std::cout << s.substr(begin, max) << std::endl;
        		}
				size_t i = begin;
        		for (i = begin; i < end && s[i] != s[end]; ++ i) {
        			char_map[static_cast<size_t>(s[i])] = false;
        		}
				begin = i + 1;
        	}
        	char_map[static_cast<size_t>(s[end])] = true;
        	++ end;
        }
		// note
		if (s.length() - begin > max) {
			max = s.length() - begin;
		}
        return max;
    }
};
