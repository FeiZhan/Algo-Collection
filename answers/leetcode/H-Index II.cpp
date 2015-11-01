//@type  Binary Search
//@result 82 / 82 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 1.61% of cpp submissions.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left(0);
		int right(citations.size() - 1);
		while (left <= right) {
			int mid((left + right) / 2);
			if (citations[mid] == citations.size() - mid) {
				return citations.size() - mid;
			}
			else if (citations[mid] > citations.size() - mid) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return citations.size() - left;
    }
};