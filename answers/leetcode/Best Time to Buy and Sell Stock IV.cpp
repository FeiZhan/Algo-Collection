//@type Dynamic Programming
//@result 211 / 211 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 1 minute ago You are here! Your runtime beats 58.38% of cpp submissions.

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
		if (k >= prices.size()) {
			return maxProfit(prices);
		}
		vector<int> global(k + 1, 0);
		vector<int> local(k + 1, 0);
		for (size_t i = 1; i < prices.size(); ++ i) {
			int diff = prices[i] - prices[i - 1];
			for (int j = k; j >= 1; -- j) {
				local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
				global[j] = max(global[j], local[j]);
			}
		}
		return global[k];
    }
	int maxProfit(const vector<int> &prices) {
		int ans = 0;
		for (size_t i = 1; i < prices.size(); ++ i) {
			if (prices[i] - prices[i - 1] > 0) {
				ans += prices[i] - prices[i - 1];
			}
		}
		return ans;
	}
};