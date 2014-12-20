// http://fisherlei.blogspot.ca/2012/12/leetcode-jump-ii.html

class Solution {
public:
	int jump(int A[], int n) {
		if (n <= 1) {
			return 0;
		}
		int start = 0;
		int end = 0;
		int count = 0;
		while (end < n - 1) {
			int max = 0;
			++ count;
			for (int i = start; i <= end; ++ i) {
				max = std::max(max, i + A[i]);
			}
			start = end + 1;
			end = max;
		}
		return count;
	}
};
