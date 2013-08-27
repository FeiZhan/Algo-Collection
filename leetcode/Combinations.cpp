// copied from leetcode
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int> > ans;
		if (n < k)
		{
			return ans;
		}
		if (1 == k)
		{
			for (int i = 1; i <= n; ++ i)
			{
				vector<int> tmp;
				tmp.push_back(i);
				ans.push_back(tmp);
			}
			return ans;
		}
		for (int i = n; i >= k; -- i)
		{
			vector<vector<int> > low = combine(i - 1, k - 1);
			for (int j = 0; j < low.size(); ++ j)
			{
				low[j].push_back(i);
				ans.push_back(low[j]);
			}
		}
		return ans;
    }
};
