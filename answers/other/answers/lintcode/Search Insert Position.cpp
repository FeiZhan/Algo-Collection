class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
		sort(A.begin(), A.end());
		size_t left = 0;
		size_t right = A.size() - 1;
		while (left <= right && right < A.size()) {
			size_t middle = (left + right) / 2;
			if ((target == A[middle]) || (middle > 0 && A[middle - 1] < target && A[middle] > target)) {
				return middle;
			}
			else if (target < A[middle]) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		return left;
    }
};
