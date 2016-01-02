class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
		int left(0);
		int right(A.size() - 1);
		while (left <= right && left >= 0 && right < A.size()) {
			int middle = (left + right) / 2;
			if (A[middle] > target) {
				right = middle - 1;
			}
			else if (A[middle] < target) {
				left = middle + 1;
			}
			else {
				while (A[left] < target && left < A.size()) {
					++ left;
				}
				while (A[right] > target && right >= 0) {
					-- right;
				}
				break;
			}
		}
		vector<int> range;
		if (left >= 0 && left < A.size() && A[left] == target) {
			range.push_back(left);
		}
		else {
			range.push_back(-1);
		}
		if (right >= 0 && right < A.size() && A[right] == target) {
			range.push_back(right);
		}
		else {
			range.push_back(-1);
		}
		return range;
    }
};
