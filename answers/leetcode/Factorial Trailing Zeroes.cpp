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
