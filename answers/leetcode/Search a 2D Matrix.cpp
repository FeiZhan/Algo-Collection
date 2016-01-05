//@result 134 / 134 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 43.59% of cpp submissions.

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows * cols - 1;
        while (low <= high)
        {
			int mid = (low + high) / 2;
			if (matrix[mid / cols][mid % cols] == target)
			{
				return true;
			} else if (matrix[mid / cols][mid % cols] < target)
			{
				low = mid + 1;
			} else if (matrix[mid / cols][mid % cols] > target)
			{
				high = mid - 1;
			}
		}
		return false;
    }
};
