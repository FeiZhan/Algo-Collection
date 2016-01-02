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

// 2015-01-10
class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		pair<int, int> p(n, k);
		if (comb_map.end() != comb_map.find(p)) {
			return comb_map[p];
		}
		vector<vector<int> > comb;
		if (1 == n && 1 == k) {
			comb.push_back(vector<int>(1, 1));
			comb_map[p] = comb;
			return comb;
		}
		if (n > k) {
			comb = combine(n - 1, k);
		}
		if (k > 1) {
			vector<vector<int> > comb1 = combine(n - 1, k - 1);
			for (size_t i = 0; i < comb1.size(); ++i) {
				comb1[i].push_back(n);
				comb.push_back(comb1[i]);
			}
		}
		else {
			comb.push_back(vector<int>(1, n));
		}
		comb_map[p] = comb;
		return comb;
	}
	map<pair<int, int>, vector<vector<int> > > comb_map;
};