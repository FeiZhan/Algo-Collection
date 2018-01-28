// binary search
//@result 1017 / 1017 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 7.64% of cpp submissions.

class Solution {
public:
    int mySqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (x == 0)
		{
			return x;
		}
		int left = 1, right = x;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int div = x / mid;
			if (mid < div)
			{
				left = mid + 1;
			}
			else if (mid > div)
			{
				right = mid - 1;
			} else
			{
				return mid;
			}
		}
		return right;
    }
};
