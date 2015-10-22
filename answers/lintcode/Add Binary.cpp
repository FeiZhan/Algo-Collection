//@level Easy
//@type String Binary
//@result Accepted Total Runtime: 33 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
		string ans;
		int carry(0);
		for (size_t i = 0; i < a.length() || i < b.length() || carry > 0; ++ i) {
			if (i < a.length()) {
				carry += static_cast<int> (a[a.length() - i - 1] - '0');
			}
			if (i < b.length()) {
				carry += static_cast<int> (b[b.length() - i - 1] - '0');
			}
			ans += static_cast<char> (carry % 2 + '0');
			carry /= 2;
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};
