//@result 157 / 157 test cases passed. Status: Accepted Runtime: 104 ms Submitted: 0 minutes ago You are here! Your runtime beats 8.95% of cpp submissions.

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (matrix.size() == 0 || 0 == matrix[0].size())
		{
			return;
		}
		bool zero_column = false, zero_row = false;
		for (int i = 0; i < matrix.size(); ++ i)
		{
			if (0 == matrix[i][0])
			{
				zero_column = true;
				break;
			}
		}
		for (int i = 0; i < matrix[0].size(); ++ i)
		{
			if (0 == matrix[0][i])
			{
				zero_row = true;
				break;
			}
		}
		for (int i = 1; i < matrix.size(); ++ i)
		{
			for (int j = 1; j < matrix[i].size(); ++ j)
			{
				if (0 == matrix[i][j])
				{
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < matrix.size(); ++ i)
		{
			if (0 == matrix[i][0])
			{
				for (int j = 1; j < matrix[i].size(); ++ j)
				{
					matrix[i][j] = 0;
				}
			}
		}
		for (int i = 1; i < matrix[0].size(); ++ i)
		{
			if (0 == matrix[0][i])
			{
				for (int j = 1; j < matrix.size(); ++ j)
				{
					matrix[j][i] = 0;
				}
			}
		}
		if (zero_column)
		{
			for (int i = 1; i < matrix.size(); ++ i)
			{
				matrix[i][0] = 0;
			}
		}
		if (zero_row)
		{
			for (int i = 0; i < matrix[0].size(); ++ i)
			{
				matrix[0][i] = 0;
			}
		} else if (zero_column)
		{
			matrix[0][0] = 0;
		}
    }
};
