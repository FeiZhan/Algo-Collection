//@result 988 / 988 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 9.17% of cpp submissions.

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (0 == divisor) {
			return INT_MAX;
		}
		long long divid = dividend;
		long long divis = divisor;
		bool negative_flag = (divid < 0) ^ (divis < 0);
		divid = std::abs(divid);
		divis = std::abs(divis);
		long long ans = 0;
		// speed up
		if (1 == divis) {
			ans = divid;
		} else {
			while (divid > 0) {
				long long div = divis;
				long long count = 1;
				while (divid >= div) {
					div <<= 1;
					count <<= 1;
				}
				ans += count >> 1;
				divid -= div >> 1;
			}
		}
		// overflow
		if (ans - 1 > INT_MAX || (ans > INT_MAX && ! negative_flag)) {
			return INT_MAX;
		}
		return ans * (negative_flag ? -1 : 1);
	}
};
