class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
		if (0 == s.length()) {
			return true;
		}
		size_t left = 0;
		size_t right = s.length() - 1;
		while (left < right && right < s.length()) {
			if (isalnum(s[left]) && isalnum(s[right])) {
				if (tolower(s[left]) != tolower(s[right])) {
					return false;
				}
				else {
					++ left;
					-- right;
				}
			}
			if (! isalnum(s[left])) {
				++ left;
			}
			if (! isalnum(s[right])) {
				-- right;
			}
		}
		return true;
    }
};
