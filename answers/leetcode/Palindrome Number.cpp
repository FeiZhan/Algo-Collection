//@result 11506 / 11506 test cases passed. Status: Accepted Runtime: 92 ms Submitted: 0 minutes ago You are here! Your runtime beats 30.64% of cpp submissions.

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		int num = x;
		int count = 0;
		while (num) {
			num /= 10;
			++ count;
		}
		-- count;
		num = x;
		while (num) {
			int temp = num;
			for (int j = 0; j < count; ++ j) {
				temp /= 10;
			}
			//cout << num << " " << num % 10 << " " << temp << endl;
			if (num % 10 != temp) {
				return false;
			}
			for (int j = 0; j < count; ++ j) {
				temp *= 10;
			}
			num -= temp;
			num /= 10;
			count -= 2;
		}
		return true;
    }
};
