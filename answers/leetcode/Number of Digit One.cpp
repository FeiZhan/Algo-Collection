//@type Math
//@result 40 / 40 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 1 minute ago You are here! Your runtime beats 2.10% of cpp submissions.

class Solution {
public:
    int countDigitOne(int n) {
        int count(0);
		for (long long i = 1; i <= n; i *= 10) {
			long long left = n / i;
			long long right = n % i;
			count += (left + 8) / 10 * i + (1 == left % 10) * (right + 1);
		}
		return count;
    }
};