//@level Medium 
//@type Backtracking Array
//@result Accepted Total Runtime: 13 ms 100% test cases passed.

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
		combination.clear();
		sort(num.begin(), num.end());
		vector<int> combi;
		combinationSum(0, combi, num, target);
		return vector<vector<int> > (combination.begin(), combination.end());
    }
	void combinationSum(size_t current, vector<int> &combi, const vector<int> &candidates, int target) {
		//cout << "test " << current << " " << candidates[current] << " -> " << target << endl;
		for (size_t i = current; i < candidates.size() && candidates[i] <= target; ++ i) {
			if (candidates[i] == target) {
				combi.push_back(candidates[i]);
				combination.insert(combi);
				combi.pop_back();
				return;
			}
			else {
				combi.push_back(candidates[i]);
				combinationSum(i + 1, combi, candidates, target - candidates[i]);
				combi.pop_back();
			}
		}
	}
	set<vector<int> > combination;
};