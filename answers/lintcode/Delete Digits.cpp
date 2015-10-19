//@level Medium 
//@type Greedy LintCode Copyright
//@result Accepted Total Runtime: 13 ms 100% test cases passed.

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
		for (size_t i = 0; i + 1 < A.size(); ++ i) {
			if (A[i] > A[i + 1]) {
				A.erase(i, 1);
				if (i >= 1) {
					i -= 2;
				}
				else {
					i = -1;
				}
				-- k;
				if (k <= 0) {
					break;
				}
			}
		}
		A = A.substr(0, A.length() - k);
		while (A.length() && '0' == A[0]) {
			A.erase(0, 1);
		}
		return A;
    }
};

