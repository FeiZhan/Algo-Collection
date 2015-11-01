class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
		if (s.length() == 0) {
			return 0;
		}
		bool start = false;
		size_t left = 0;
		size_t right = s.length() - 1;
		for (size_t i = s.length() - 1; i < s.length(); -- i) {
			if (' ' != s[i] && ! start) {
				right = i;
				start = true;
			}
			else if (' ' == s[i] && start) {
				left = i + 1;
				break;
			}
		}
		return right - left + 1;
    }
};
