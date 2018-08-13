//@result 502 / 502 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 6.95% of cpp submissions.

class Solution {
public:
	int trailingZeroes(int n) {
		int zero_num = 0;
		while (n > 0) {
			zero_num += n / 5;
			n /= 5;
		}
		return zero_num;
	}
};
