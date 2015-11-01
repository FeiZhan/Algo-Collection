//@type  Array
//@result 64 / 64 test cases passed. Status: Accepted Runtime: 24 ms Submitted: 0 minutes ago You are here! Your runtime beats 24.03% of cpp submissions.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> major_list;
		if (nums.size() == 0) {
			return major_list;
		}
		int major[2];
		major[0] = nums[0];
		major[1] = nums[0];
		for (size_t i = 1; i < nums.size(); ++ i) {
			if (nums[i] != major[0]) {
				major[1] = nums[i];
				break;
			}
		}
		int count[2] = {0, 0};
		for (size_t i = 0; i < nums.size(); ++ i) {
			if (nums[i] == major[0]) {
				++ count[0];
			}
			else if (nums[i] == major[1]) {
				++ count[1];
			}
			else if (0 == count[0]) {
				major[0] = nums[i];
				count[0] = 1;
			}
			else if (0 == count[1]) {
				major[1] = nums[i];
				count[1] = 1;
			}
			else {
				-- count[0];
				-- count[1];
			}
		}
		count[0] = count[1] = 0;
		for (size_t i = 0; i < nums.size(); ++ i) {
			for (int j = 0; j < 2; ++ j) {
				if (nums[i] == major[j]) {
					++ count[j];
				}
			}
		}
		set<int> major_set;
		for (int j = 0; j < 2; ++ j) {
			if (count[j] > nums.size() / 3) {
				major_set.insert(major[j]);
			}
		}
		major_list = vector<int> (major_set.begin(), major_set.end());
		return major_list;
    }
};