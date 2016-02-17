class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
		for (int i = m - 1, j = n - 1, k = m + n - 1; k >= 0; -- k) {
			if (i < 0 && j >= 0) {
				A[k] = B[j];
				-- j;
			}
			else if (j < 0 && i >= 0) {
				A[k] = A[i];
				-- i;
			}
			else if (i >= 0 && j >= 0) {
				if (A[i] > B[j]) {
					A[k] = A[i];
					-- i;
				}
				else {
					A[k] = B[j];
					-- j;
				}
			}
		}
    }
};
