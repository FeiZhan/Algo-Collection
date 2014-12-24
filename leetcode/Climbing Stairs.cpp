class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<int> ways;
		ways.push_back(0);
		ways.push_back(1);
		ways.push_back(2);
		for (int i = 3; i <= n; ++ i)
		{
			ways.push_back( ways[i - 1] + ways[i - 2] );
		}
		return ways[n];
    }
};

// 2014-12-24
class Solution {
public:
    int climbStairs(int n) {
		std::vector<int> dp(n + 1, 0);
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++ i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
    }
};
