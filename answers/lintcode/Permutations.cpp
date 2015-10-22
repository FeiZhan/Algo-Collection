//@result Accepted Total Runtime: 24 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
		permutation.clear();
		vector<int> perm;
		vector<bool> visit_flag(nums.size(), false);
		for (size_t i = 0; i < nums.size(); ++ i) {
			perm.push_back(nums[i]);
			visit_flag[i] = true;
			permute(perm, visit_flag, nums);
			perm.pop_back();
			visit_flag[i] = false;
		}
		return permutation;
    }
	void permute(vector<int> &perm, vector<bool> &visit_flag, const vector<int> &nums) {
		bool flag = false;
		for (size_t i = 0; i < nums.size(); ++ i) {
			if (! visit_flag[i]) {
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

