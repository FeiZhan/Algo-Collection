//@result 15 / 15 test cases passed. Status: Accepted Runtime: 20 ms Submitted: 0 minutes ago You are here! Your runtime beats 25.55% of cpp submissions.

// bit manipulation XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			ans ^= nums[i];
		}
		return ans;
	}
};
