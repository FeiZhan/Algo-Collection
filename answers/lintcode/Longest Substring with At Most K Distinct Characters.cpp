//@level Medium 
//@type String Two Pointers LintCode Copyright Hash Table
//@result Accepted Total Runtime: 935 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
		map<char, int> char_map;
		int length(0);
		int max_length(0);
		for (size_t i = 0; i < s.length(); ++ i) {
			if (char_map.end() == char_map.find(s[i])) {
				char_map[s[i]] = 0;
			}
			++ char_map[s[i]];
			++ length;
			if (char_map.size() > k) {
				-- length;
				-- char_map[s[i - length]];
				if (char_map[s[i - length]] <= 0) {
					char_map.erase(s[i - length]);
				}
			}
			max_length = max(max_length, length);
		}
		return max_length;
    }
};
