// my own idea, better than leetcode discussion
//@result 86 / 86 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 6.69% of cpp submissions.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
		int red_end = 0, blue_begin = nums.size();
		for (int i = 0; i < blue_begin; ++ i)
		{
			switch (nums[i])
			{
			case 0:
				swap(red_end, i, nums);
				++ red_end;
				break;
			case 2:
				swap(blue_begin - 1, i, nums);
				-- blue_begin;
				-- i;
				break;
			}
		}
    }
    void swap(int a, int b, vector<int>& nums)
    {
		int tmp = nums[a];
		nums[a] = nums[b];
		nums[b] = tmp;
	}
};
