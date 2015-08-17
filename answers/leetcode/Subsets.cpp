// undone
	bool equal(std::vector<int> &l, std::vector<int> &r)
	{
		if (l.size() != r.size())
		{
			return false;
		}
		for (int i = 0; i < l.size(); ++ i)
		{
			if (l[i] != r[i])
			{
				return false;
			}
		}
		return true;
	}
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<std::vector<int> > ans;
		ans.push_back( std::vector<int>() );
		std::sort(S.begin(), S.end());
		subsets_rec(S, ans);
		ans.erase(std::unique(ans.begin(), ans.end(), equal), ans.end());
		return ans;
    }
    void subsets_rec(const std::vector<int> &s, std::vector<std::vector<int> > &ans)
    {
		if (s.size() == 0)
		{
			return;
		}
		ans.push_back(s);
		for (int i = 0; i < s.size(); ++ i)
		{
			std::vector<int> now = s;
			now.erase(now.begin() + i);
			subsets_rec(now, ans);
		}
		return;
	}
};
