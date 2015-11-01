//@level Medium 
//@type Two Pointers LintCode Copyright Sort Array
//@result Accepted Total Runtime: 1297 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
		multiset<int> aset(A.begin(), A.end());
		int smallest(INT_MAX);
		for (size_t i = 0; i < B.size(); ++ i) {
			multiset<int>::iterator lower = aset.lower_bound(B[i]);
			if (aset.end() != lower) {
				smallest = min(smallest, abs(*lower - B[i]));
			}
			if (aset.begin() != lower) {
				smallest = min(smallest, abs(*prev(lower) - B[i]));
			}
		}
		return smallest;
    }
};

