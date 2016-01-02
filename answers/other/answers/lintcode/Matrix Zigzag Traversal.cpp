//@level Easy
//@type LintCode Copyright Matrix
//@result Accepted Total Runtime: 12 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
		vector<int> zigzag;
		if (0 == matrix.size()) {
			return zigzag;
		}
		bool direction(true);
		for (size_t i = 0; i < matrix.size() + matrix[0].size(); ++ i) {
			direction = ! direction;
			for (size_t j = 0; j <= i; ++ j) {
				size_t x = direction ? j : i - j;
				size_t y = direction ? i - j : j;
				if (x < matrix.size() && y < matrix[x].size()) {
					zigzag.push_back(matrix[x][y]);
				}
			}
		}
		return zigzag;
    }
};
