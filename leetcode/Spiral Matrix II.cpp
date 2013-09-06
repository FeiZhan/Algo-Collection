//WA
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<std::vector<int> > ans;
		if (n <= 0)
		{
			return ans;
		}
		for (int i = 0; i < n; ++ i)
		{
			ans.push_back(std::vector<int> (n));
		}
		generate(n, 0, ans);
		return ans;
    }
	void generate(int n, int level, std::vector<std::vector<int> > &ans)
	{
		if (n - 2 * level < 1)
		{
			return;
		}
		if (n - 2 * level == 1)
		{
			ans[n / 2][n / 2] = n * n;
			return;
		}
		int begin = 0;
		for (int i = 0, factor = n - 1; i < level && factor > 0; ++ i, factor -= 2)
		{
			begin += factor;
		}
		begin = begin * 4 + 1;
		for (int i = 0; i < n - level * 2; ++ i)
		{
			ans[level][i] = i + begin;
			ans[n - 1 - level][i] = 3 * n - 2 - i;
		}
		for (int i = 0; i < n - level * 2 - 2; ++ i)
		{
			ans[i + level + 1][n - level - 1] = begin + (n - level * 2 - 1) + 1 + i;
			ans[i + level + 1][level] = begin + (n - level * 2 - 1) * 4 - 1 - i;
		}
		generate(n, level + 1, ans);
	}
};
