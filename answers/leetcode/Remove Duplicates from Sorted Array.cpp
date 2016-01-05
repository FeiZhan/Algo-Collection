//@result 161 / 161 test cases passed. Status: Accepted Runtime: 32 ms Submitted: 0 minutes ago You are here! Your runtime beats 42.19% of cpp submissions.

#include <iostream>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (nums.size() <= 0)
        {
			return 0;
		}
		int head = -1, last = -1, size = nums.size(), previous = nums[0];
		for (int i = 1; i < nums.size(); ++ i)
		{
			if (nums[i] == previous)
			{
				if (-1 == last)
				{
					head = i;
				} else
				{
					nums[last] = i;
				}
				last = i;
				// record the previous one
				previous = nums[i];
				nums[i] = -1;
				-- size;
			} else
			{
				previous = nums[i];
			}
		}
		int count = 0;
		for (int i = 0; i < nums.size(); ++ i)
		{
			if (i == head)
			{
				++ count;
				head = nums[head];
			} else
			{
		//std::cout << "head " << head << std::endl;
				nums[i - count] = nums[i];
			}
		}
		return size;
    }
    void output(const int A[], int n)
    {
		for (int i = 0; i < n; ++ i)
		{
			std::cout << A[i] << " ";
		}
		std::cout << std::endl;
	}
};
int main()
{
	Solution s;
	const int SIZE = 3;
	int A[SIZE] = {1, 1, 2};
	std::cout << s.removeDuplicates(A, SIZE) << std::endl;
	s.output(A, SIZE);
	return 0;
}
