//@type Divide and Conquer Binary Search
//@result 127 / 127 test cases passed. Status: Accepted Runtime: 580 ms Submitted: 0 minutes ago You are here! Your runtime beats 20.22% of cpp submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (size_t i = 0; i < matrix.size(); ++ i) {
			if (bSearch(0, matrix[i].size(), matrix[i], target)) {
				return true;
			}
		}
		return false;
    }
	bool bSearch(int left, int right, const vector<int> &row, const int &target) {
		if (left >= right) {
			return false;
		}
		int middle = (left + right) / 2;
		if (row[middle] == target) {
			return true;
		}
		else if (row[middle] > target) {
			return bSearch(left, middle, row, target);
		}
		else {
			return bSearch(middle + 1, right, row, target);
		}
	}
};

//@algorithm binary search
//@time complexity O(m + n)
//@space complexity O(1)
//@result 127 / 127 test cases passed. Status: Accepted Runtime: 300 ms You are here! Your runtime beats 36.09% of cpp submissions.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t row = 0;
        size_t column = matrix[row].size() - 1;
        while (row < matrix.size() && column < matrix[row].size()) {
            if (matrix[row][column] == target) {
                return true;
            }
            else if (matrix[row][column] > target) {
                -- column;
            }
            else {
                ++ row;
            }
        }
        return false;
    }
};
