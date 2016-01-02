//@level Medium 
//@type LintCode Copyright Dynamic Programming Backpack
//@result Accepted Total Runtime: 867 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
		vector<int> dp(m + 1, 0);
		for (size_t i = 0; i < A.size(); ++ i) {
			// reverse order to avoid pick the same item multiple times
			for (size_t j = dp.size() - 1; j >= A[i] && j < dp.size(); -- j) {
				dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
			}
		}
		return dp[dp.size() - 1];
    }
};
