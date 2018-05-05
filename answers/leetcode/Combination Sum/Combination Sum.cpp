class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> cand;
        for (int i = 0; i < candidates.size(); ++ i)
        {
			if (candidates[i] <= target)
			{
				cand.push_back(candidates[i]);
			}
		}
        for (int i = 0; i < cand.size(); ++ i)
        {
			if (cand[i] == target)
			{
				vector<int> tmp;
				tmp.push_back(cand[i]);
				ans.push_back(tmp);
				continue;
			}
			vector<vector<int> > second = combinationSum(cand, target - cand[i]);
			for (int j = 0; j < second.size(); ++ j)
			{
				second[j].push_back(cand[i]);
				sort(second[j].begin(), second[j].end());
				// manual unique
				bool same_flag = false;
				for (int k = 0; k < ans.size(); ++ k)
				{
					if (second[j].size() != ans[k].size())
					{
						continue;
					}
					bool flag = false;
					for (int m = 0; m < ans[k].size(); ++ m)
					{
						if (ans[k][m] != second[j][m])
						{
							flag = true;
							break;
						}
					}
					if (false == flag)
					{
						same_flag = true;
						break;
					}
				}
				if (false == same_flag)
				{
					ans.push_back(second[j]);
				}
			}
		}
		//unique(ans.begin(), ans.end());
		return ans;
    }
};
