//@result 172 / 172 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 76.35% of cpp submissions.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> >combi_list;
        vector<int> combi;
        dfs(0, target, candidates, combi, combi_list);
        return combi_list;
    }
    void dfs(size_t current, int target, const vector<int> &candidates, vector<int> &combi, vector<vector<int> > &combi_list) {
    	if (0 == target) {
    		combi_list.push_back(combi);
    		return;
    	}
    	for (size_t i = current; i < candidates.size() && candidates[i] <= target; ++ i) {
    		if (current == i || candidates[i] != candidates[i - 1]) {
    			combi.push_back(candidates[i]);
    			dfs(i + 1, target - candidates[i], candidates, combi, combi_list);
    			combi.pop_back();
    		}
    	}
    }
};