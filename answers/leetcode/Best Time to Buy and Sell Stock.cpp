class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2)
        {
			return 0;
		}
		int max = 0, min = INT_MAX;
		for (int i = 0; i < prices.size(); ++ i)
		{
			if (prices[i] < min)
			{
				min = prices[i];
			}
			if (prices[i] - min > max)
			{
				max = prices[i] - min;
			}
		}
		return max;
    }
};
