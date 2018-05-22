//@type Array
//@time complexity O(n)
//@space complexity O(n)
//@result 27 / 27 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 1.50% of cpp submissions.

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ranges;
        size_t begin(0);
		for (size_t i = 1; i <= nums.size(); ++ i) {
			if (nums[i] != nums[i - 1] + 1 || i == nums.size()) {
				string range = to_string(nums[begin]);
				if (begin < i - 1) {
					range += "->" + to_string(nums[i - 1]);
				}
				ranges.push_back(range);
				begin = i;
			}
		}
		return ranges;
    }
};
