//@type Math
//@result 1012 / 1012 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 69.38% of cpp submissions.

class Solution {
public:
    bool isUgly(int num) {
		if (0 == num) {
			return false;
		}
        while (0 == num % 2) {
			num /= 2;
		}
        while (0 == num % 3) {
			num /= 3;
		}
        while (0 == num % 5) {
			num /= 5;
		}
		return num == 1;
    }
};