//@level Medium 
//@type LintCode Copyright Dynamic Programming Backpack
//@result Accepted Total Runtime: 40 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
		vector<int> dp(m + 1, 0);
		for (size_t i = 0; i < A.size(); ++ i) {
			for (size_t j = dp.size() - 1; j >= A[i] && j < dp.size(); -- j) {
				dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
			}
		}
		return dp[dp.size() - 1];
    }
};
