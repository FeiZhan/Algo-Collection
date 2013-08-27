class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int max = 0;
		for (int i = 0; i < matrix.size(); ++ i)
		{
			for (int j = 0; j < matrix[i].size(); ++ j)
			{
				if ('1' != matrix[i][j])
				{
					continue;
				}
				int width = 1;
				while (i + width < matrix.size() && matrix[i + width][j] == '1')
				{
					++ width;
					if (i + width >= matrix.size())
					{
						width = matrix.size() - 1 - i;
						break;
					}
				}
				int height;
				for (int k = 0; k < width && i + k < matrix.size(); ++ k)
				{
					for (height = 1; j + height < matrix[i + k].size(); ++ height)
					{
						if (matrix[i + k][j + height] == '0')
						{
							break;
						}
					}
					if (matrix[i + k][j + height] == '0')
					{
						width = k;
						-- height;
						break;
					}
				}
				for (int k = 0; k < width && i + k < matrix.size(); ++ k)
				{
					for (int m = 0; m < height && j + m < matrix[i + k].size(); ++ m)
					{
						matrix[i + k][j + m] = '2';
					}
				}
				max = (max > height * width) ? max : height * width;
			}
		}
		return max;
    }
};
