class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return spiral(matrix, 0);
    }
    vector<int> spiral(const vector<vector<int> > &matrix, const int level)
    {
		vector<int> ans;
		if (matrix.size() == 0 || level * 2 + 1 > matrix.size() || level * 2 + 1 > matrix[0].size())
		{
			return ans;
		}
		// up
		for (int i = level; i < matrix[0].size() - level; ++ i)
		{
			ans.push_back(matrix[level][i]);
		}
		// right
		for (int i = level + 1; i < matrix.size() - level; ++ i)
		{
			ans.push_back(matrix[i][matrix[0].size() - level]);
		}
		// down
		for (int i = level + 1; i < matrix[0].size() - level; ++ i)
		{
			ans.push_back(matrix[matrix.size() - level][matrix[0].size() - i]);
		}
		// left
		for (int i = level + 1; i < matrix.size() - level; ++ i)
		{
			ans.push_back(matrix[i][matrix[0].size() - level]);
		}
	}
};
