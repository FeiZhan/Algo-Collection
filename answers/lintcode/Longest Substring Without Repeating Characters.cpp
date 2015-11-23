class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        map<char, size_t> char_map;
        size_t start = 0;
        size_t longest = 0;
        for (size_t i = 0; i < s.length(); ++ i) {
            if (char_map.end() != char_map.find(s[i])) {
                for (size_t j = start; j < char_map[s[i]]; ++ j) {
                    char_map.erase(s[j]);
                }
                start = char_map[s[i]] + 1;
            }
            char_map[s[i]] = i;
            longest = max(longest, i - start);
        }
        return min(longest + 1, s.length());
    }
};
