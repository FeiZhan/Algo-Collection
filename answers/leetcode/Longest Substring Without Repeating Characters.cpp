//@result 981 / 981 test cases passed. Status: Accepted Runtime: 16 ms Submitted: 0 minutes ago You are here! Your runtime beats 62.84% of cpp submissions.
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
