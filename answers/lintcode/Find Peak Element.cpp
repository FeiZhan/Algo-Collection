//@level Medium 
//@type Binary Search LintCode Copyright Array
//@result Accepted Total Runtime: 16 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
		size_t left(0);
		size_t right(A.size() - 1);
		size_t middle(0);
		while (left <= right) {
			middle = (left + right) / 2;
			if (middle > 0 && middle < A.size() && (A[middle - 1] < A[middle] && A[middle] > A[middle + 1])) {
				break;
			}
			else if (0 == middle || A[middle - 1] < A[middle] && A[middle] < A[middle + 1]) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		return middle;
    }
};

