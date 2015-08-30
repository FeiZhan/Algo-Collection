class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int carry = 1;
		int pos = digits.size() - 1;
		while (carry && pos >= 0)
		{
			digits[pos] += carry;
			carry = digits[pos] / 10;
			digits[pos] %= 10;
			-- pos;
		}
		if (carry)
		{
			digits.insert(digits.begin(), carry);
		}
		return digits;
    }
};
