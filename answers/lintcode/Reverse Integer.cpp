class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
		long long reverse(0);
		while (n) {
			reverse = reverse * 10 + n % 10;
			n /= 10;
		}
		return (reverse > INT_MAX || reverse < INT_MIN) ? 0 : reverse;
    }
};
