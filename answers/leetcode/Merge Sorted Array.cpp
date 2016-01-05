// merge in reverse order
//@result 59 / 59 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 13.35% of cpp submissions.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int a_pos = m - 1, b_pos = n - 1, pos = m + n - 1;
		while (pos >= 0)
		{
			if (b_pos < 0 || (a_pos >= 0 && nums1[a_pos] > nums2[b_pos]))
			{
				nums1[pos] = nums1[a_pos];
				-- a_pos;
			} else
			{
				nums1[pos] = nums2[b_pos];
				-- b_pos;
			}
			-- pos;
		};
    }
};
