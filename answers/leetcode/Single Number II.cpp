//@result 11 / 11 test cases passed. Status: Accepted Runtime: 16 ms Submitted: 0 minutes ago You are here! Your runtime beats 54.39% of cpp submissions.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		vector<int> bit_list(32, 0);
		for (int i = 0; i < nums.size(); ++ i) {
			int num = nums[i];
			int bit = 0;
			while (num && bit < bit_list.size()) {
				bit_list[bit] += num & 1;
				num >>= 1;
				++ bit;
			}
		}
		int ans = 0;
		for (size_t i = 0; i < bit_list.size(); ++ i) {
			if (bit_list[i] % 3) {
				ans |= 1 << i;
			}
		}
		return ans;
	}
};

//@result 11 / 11 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 70.48% of cpp submissions.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int one = 0, two = 0, three = 0;
		for (int i = 0; i < nums.size(); ++ i) {
			two |= one & nums[i];
			one ^= nums[i];
			three = one & two;
			one &= ~ three;
			two &= ~ three;
		}
		return one;
	}
};
