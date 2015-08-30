class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int price = 0;
		for (int i = 1; i < prices.size(); ++ i)
		{
			if (prices[i] > prices[i - 1])
			{
				price += prices[i] - prices[i - 1];
			}
		}
		return price;
    }
};

// greedy
// 2014-09-06
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		size_t buy = 0;
		int sum = 0;
		for (size_t i = 1; i < prices.size(); ++ i)
		{
			if (prices[i] > prices[buy])
			{
				sum += prices[i] - prices[buy];
			}
			buy = i;
		}
		return sum;
    }
};
