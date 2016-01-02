//@type Math
//@time complexity O(len(n))
//@space complexity O(1)
//@result 40 / 40 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 1 minute ago You are here! Your runtime beats 2.81% of cpp submissions.

class Solution {
public:
    int countDigitOne(int n) {
        int count(0);
		for (long long i = 1; i <= n; i *= 10) {
			long long left = n / i / 10;
			long long right = n % i;
            int current = n / i % 10;
            // left + current + right
            count += left * i + (current > 1) * i + (1 == current) * (right + 1);
		}
		return count;
    }
};
