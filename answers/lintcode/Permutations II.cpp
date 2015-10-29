class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
		sort(nums.begin(), nums.end());
		permutation.clear();
		vector<int> perm;
		vector<bool> visit_flag(nums.size(), false);
		for (size_t i = 0; i < nums.size(); ++ i) {
			// check here
			if (! (i > 0 && nums[i] == nums[i - 1])) {
				perm.push_back(nums[i]);
				visit_flag[i] = true;
				permute(perm, visit_flag, nums);
				perm.pop_back();
				visit_flag[i] = false;
			}
		}
		return permutation;
    }
	void permute(vector<int> &perm, vector<bool> &visit_flag, const vector<int> &nums) {
		bool flag = false;
		for (size_t i = 0; i < nums.size(); ++ i) {
			if (! visit_flag[i] && ! (i > 0 && nums[i] == nums[i - 1] && ! visit_flag[i - 1])) {
				flag = true;
				perm.push_back(nums[i]);
				visit_flag[i] = true;
				permute(perm, visit_flag, nums);
				perm.pop_back();
				visit_flag[i] = false;
			}
		}
		if (! flag) {
			permutation.push_back(perm);
		}
	}
	vector<vector<int> > permutation;
};
