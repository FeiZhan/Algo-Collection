class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
		vector<int> merged;
		for (size_t i = 0, j = 0; i < A.size() || j < B.size();) {
			if (i < A.size() && j < B.size()) {
				if (A[i] < B[j]) {
					merged.push_back(A[i]);
					++ i;
				}
				else {
					merged.push_back(B[j]);
					++ j;
				}
			}
			else if (i < A.size()) {
				merged.push_back(A[i]);
				++ i;
			}
			else if (j < B.size()) {
				merged.push_back(B[j]);
				++ j;
			}
		}
		return merged;
    }
};
