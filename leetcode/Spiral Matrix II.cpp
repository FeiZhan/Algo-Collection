// simply iterate, copied from leetcode

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<std::vector<int> > ans(n, std::vector<int>(n));
		int start = 0, end = n - 1, num = 1;
		while (start < end)
		{
			for (int i = start; i < end; ++ i)
			{
				ans[start][i] = num;
				++ num;
			}
			for (int i = start; i < end; ++ i)
			{
				ans[i][end] = num;
				++ num;
			}
			for (int i = end; i > start; -- i)
			{
				ans[end][i] = num;
				++ num;
			}
			for (int i = end; i > start; -- i)
			{
				ans[i][start] = num;
				++ num;
			}
			++ start;
			-- end;
		}
		if (start == end)
		{
			ans[start][end] = num;
		}
		return ans;
    }
};
