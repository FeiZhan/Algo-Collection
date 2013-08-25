// copied from leetcode
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (0 == prices.size())
		{
			return 0;
		}
		std::vector<int> history(prices.size(), 0), future(prices.size(), 0);
		int valley = prices[0];
		for (int i = 0; i < prices.size(); ++ i)
		{
			valley = std::min(valley, prices[i]);
			if (i > 0)
			{
				history[i] = std::max(history[i - 1], prices[i] - valley);
			}
		}
		int peak = prices[prices.size() - 1], max = 0;
		for (int i = prices.size() - 1; i >= 0; -- i)
		{
			peak = std::max(peak, prices[i]);
			if (i < prices.size() - 1)
			{
				future[i] = std::max(future[i + 1], peak - prices[i]);
			}
			max = std::max(max, history[i] + future[i]);
		}
		return max;
    }
};
