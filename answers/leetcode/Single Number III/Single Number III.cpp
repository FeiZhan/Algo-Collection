//@type Bit Manipulation
//@result 30 / 30 test cases passed. Status: Accepted Runtime: 20 ms Submitted: 0 minutes ago You are here! Your runtime beats 23.50% of cpp submissions.

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors(0);
		for (size_t i = 0; i < nums.size(); ++ i) {
			xors ^= nums[i];
		}
		int pos(0);
		for (int i = 0; i < 32; ++ i) {
			if ((xors >> i) & 1) {
				pos = i;
				break;
			}
		}
		int ones(0);
		int zeros(0);
		for (size_t i = 0; i < nums.size(); ++ i) {
			if ((nums[i] >> pos) & 1) {
				ones ^= nums[i];
			}
			else {
				zeros ^= nums[i];
			}
		}
		vector<int> ans;
		ans.push_back(ones);
		ans.push_back(zeros);
		return ans;
    }
};