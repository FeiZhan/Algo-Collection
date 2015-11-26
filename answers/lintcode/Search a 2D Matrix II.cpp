class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return 0;
        }
        size_t row = 0;
        size_t column = matrix[row].size() - 1;
        int occurrence = 0;
        while (row < matrix.size() && column < matrix[row].size()) {
            if (target == matrix[row][column]) {
                ++ occurrence;
                ++ row;
                -- column;
            }
            else if (target < matrix[row][column]) {
                -- column;
            }
            else {
                ++ row;
            }
        }
        return occurrence;
    }
};
