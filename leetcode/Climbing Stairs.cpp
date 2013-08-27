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
