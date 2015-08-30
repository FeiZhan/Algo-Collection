class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		if (matrix.size() == 0)
		{
			return;
		}
		size_t width = matrix[0].size() - 1;
		size_t height = matrix.size() - 1;
		size_t half_width = static_cast<size_t>(matrix[0].size() / 2.0 + 0.5);
		size_t half_height = matrix.size() / 2.0;
		for (size_t i = 0; i < half_height; ++ i)
		{
			for (size_t j = 0; j < half_width; ++ j)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[height - j][i];
				matrix[height - j][i] = matrix[height - i][width - j];
				matrix[height - i][width - j] = matrix[j][width - i];
				 matrix[j][width - i] = temp;
			}
		}
    }
};
