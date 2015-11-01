class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
		size_t left = 0;
		bool increase = false;
		int longest = A.size() ? 1 : 0;
		for (size_t i = 1; i < A.size(); ++ i) {
			if (A[i - 1] > A[i] && increase) {
				left = i - 1;
				increase = false;
			}
			else if (A[i - 1] < A[i] && ! increase) {
				left = i - 1;
				increase = true;
			}
			longest = max(longest, int(i - left) + 1);
		}
		return longest;
    }
};
