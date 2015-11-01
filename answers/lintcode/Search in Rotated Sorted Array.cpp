class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
		size_t left(0);
		size_t right(A.size() - 1);
		while (left <= right && right < A.size()) {
			size_t middle = (left + right) / 2;
			if (A[middle] == target) {
				return middle;
			}
			if (A[middle] >= A[left]) {
				if (A[left] <= target && target < A[middle]) {
					right = middle - 1;
				}
				else {
					left = middle + 1;
				}
			}
			else {
				if (A[middle] < target && target <= A[right]) {
					left = middle + 1;
				}
				else {
					right = middle - 1;
				}
			}
		}
		return -1;
    }
};
