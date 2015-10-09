//@result 1101 / 1101 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 16.11% of cpp submissions.

class Solution {
public:
    int addDigits(int num) {
		int sum(0);
        while (num) {
			sum += num % 10;
			num /= 10;
		}
		if (sum >= 10) {
			return addDigits(sum);
		}
		return sum;
    }
};