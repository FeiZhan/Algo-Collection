class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
		int carry(1);
		for (size_t i = digits.size() - 1; i < digits.size(); -- i) {
			digits[i] += carry;
			carry = digits[i] / 10;
			digits[i] %= 10;
		}
		if (carry) {
			digits.insert(digits.begin(), carry);
		}
		return digits;
    }
};
