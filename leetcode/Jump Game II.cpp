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

// 2015-01-12
//@type greedy
// less space efficient
class Solution {
public:
	int jump(int A[], int n) {
		vector<int> step(n, INT_MAX);
		step[0] = 0;
		int largest = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = largest; j <= i + A[i] && j < n; ++j) {
				step[j] = std::min(step[j], step[i] + 1);
			}
			largest = std::max(largest, i + A[i]);
		}
		return step[n - 1];
	}
};