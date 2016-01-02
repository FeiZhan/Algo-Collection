class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (0 == matrix.size() || 0 == matrix[0].size()) {
        	return false;
        }
        size_t left = 0;
        size_t right = matrix.size() - 1;
        while (left <= right && right < matrix.size()) {
        	size_t middle = (left + right) / 2;
        	if (target < matrix[middle][0]) {
        		right = middle - 1;
        	}
        	else if (target >= matrix[middle][0] && (middle + 1 >= matrix.size() || target < matrix[middle + 1][0])) {
        		break;
        	}
        	else {
        		left = middle + 1;
        	}
        }
        size_t row = (left + right) / 2;
        left = 0;
        right = matrix[row].size() - 1;
        while (left <= right && right < matrix[row].size()) {
        	size_t middle = (left + right) / 2;
        	if (target == matrix[row][middle]) {
        		return true;
        	}
        	if (target < matrix[row][middle]) {
        		right = middle - 1;
        	}
        	else {
        		left = middle + 1;
        	}
        }
        return false;
    }
};

