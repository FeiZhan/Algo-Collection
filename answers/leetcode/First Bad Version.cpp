//@type  Binary Search
//@result 21 / 21 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		return firstBadVersion(1, n);
	}
    int firstBadVersion(int begin, int end) {
        if (begin == end) {
			return end;
		}
		else {
			int half = begin + (end - begin) / 2;
			if (isBadVersion(half)) {
				return firstBadVersion(begin, half);
			}
			else {
				return firstBadVersion(half + 1, end);
			}
		}
    }
};