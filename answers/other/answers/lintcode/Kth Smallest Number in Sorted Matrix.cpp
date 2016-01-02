class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
		if (0 == matrix.size() || 0 == matrix[0].size()) {
			return 0;
		}
		else if (k <= 1) {
			return matrix[0][0];
		}
		else {
			matrix[0][0] = matrix[matrix.size() - 1][matrix[matrix.size() - 1].size() - 1];
			size_t i = 0;
			size_t j = 0;
			while (i < matrix.size() && j < matrix[matrix.size() - 1].size()) {
				if ((j + 1 >= matrix[matrix.size() - 1].size() || (i + 1 < matrix.size() && j + 1 < matrix[matrix.size() - 1].size() && matrix[i + 1][j] < matrix[i][j + 1])) && matrix[i][j] > matrix[i + 1][j]) {
					int temp = matrix[i][j];
					matrix[i][j] = matrix[i + 1][j];
					matrix[i + 1][j] = temp;
					++ i;
				}
				else if ((i + 1 >= matrix.size() || (i + 1 < matrix.size() && j + 1 < matrix[matrix.size() - 1].size() && matrix[i + 1][j] >= matrix[i][j + 1])) && matrix[i][j] > matrix[i][j + 1]) {
					int temp = matrix[i][j];
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = temp;
					++ j;
				}
				else {
					break;
				}
			}
			return kthSmallest(matrix, k - 1);
		}
    }
};
