class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
		string reversed;
		size_t begin = 0;
		for (size_t i = 0; i <= s.length(); ++ i) {
			if (s.length() == i || ' ' == s[i]) {
				if (i - begin >= 1) {
					reversed = s.substr(begin, i - begin) + string(" ") + reversed;
				}
				begin = i + 1;
			}
		}
		if (reversed.length() || ' ' == reversed.back()) {
			reversed = reversed.substr(0, reversed.length() - 1);
		}
		return reversed;
    }
};
