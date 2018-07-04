//@result 265 / 265 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 1 minute ago You are here! Your runtime beats 15.58% of cpp submissions.

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		size_t vio_pos = INT_MAX;
		for (size_t i = num.size() - 2; i < num.size(); --i) {
			if (num[i] < num[i + 1]) {
				vio_pos = i;
				break;
			}
		}
		if (vio_pos != INT_MAX) {
			size_t change_pos = 0;
			size_t min_change = INT_MAX;
			for (size_t i = num.size() - 1; i > vio_pos; --i) {
				if (num[i] > num[vio_pos] && num[i] <= min_change) {
					change_pos = i;
					min_change = num[i];
				}
			}
			int temp = num[vio_pos];
			num[vio_pos] = num[change_pos];
			num[change_pos] = temp;
			sort(num.begin() + vio_pos + 1, num.end());
		}
		else {
			sort(num.begin(), num.end());
		}
	}
};
