// 2015-01-14
//@type binary search
//@result 188 / 188 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 12.61% of cpp submissions.
class Solution {
public:
	int findMin(vector<int> &num) {
		if (0 == num.size()) {
			return 0;
		}
		int left = 0, right = num.size() - 1;
		int min = INT_MAX;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (num[left] < num[mid]) {
				min = std::min(num[left], min);
				left = mid + 1;
			}
			else if (num[left] > num[mid]) {
				min = std::min(num[mid], min);
				right = mid - 1;
			}
			else {
				min = std::min(num[mid], min);
				++ left;
			}
		}
		return min;
	}
};
