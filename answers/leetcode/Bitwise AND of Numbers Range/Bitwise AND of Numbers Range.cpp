//@type Bit Manipulation
//@result 8266 / 8266 test cases passed. Status: Accepted Runtime: 80 ms Submitted: 39 minutes ago You are here! Your runtime beats 12.79% of cpp submissions.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count(0);
		while (m != n) {
			m >>= 1;
			n >>= 1;
			++ count;
		}
		return m << count;
    }
};