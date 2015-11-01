//@level Medium 
//@type Cracking The Coding Interview Bit Manipulation
//@result Accepted Total Runtime: 5 ms 100% test cases passed.

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
		int carry(0);
		while (b) {
			carry = (a & b) << 1;
			a ^= b;
			b = carry;
		}
		return a;
    }
};
