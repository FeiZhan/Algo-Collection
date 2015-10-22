//@level Medium 
//@type Backtracking Array
//@result Accepted Total Runtime: 17 ms 100% test cases passed.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
		combination.clear();
		sort(candidates.begin(), candidates.end());
		candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
		vector<int> combi;
		combinationSum(0, combi, candidates, target);
		return combination;
    }
	void combinationSum(size_t current, vector<int> &combi, const vector<int> &candidates, int target) {
		//cout << "test " << current << " " << candidates[current] << " -> " << target << endl;
		for (size_t i = current; i < candidates.size() && candidates[i] <= target; ++ i) {
			if (candidates[i] == target) {
				combination.push_back(combi);
				combination[combination.size() - 1].push_back(candidates[i]);
				return;
			}
			else {
				combi.push_back(candidates[i]);
				combinationSum(i, combi, candidates, target - candidates[i]);
				combi.pop_back();
			}
		}
	}
	vector<vector<int> > combination;
};

int main() {
	// your code goes here
	Solution s;
	//[2,3,5], 7
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(5);
	int target = 7;
	vector<vector<int> > combination = s.combinationSum(candidates, target);
	for (size_t i = 0; i < combination.size(); ++ i) {
		for (size_t j = 0; j < combination[i].size(); ++ j) {
			cout << combination[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}