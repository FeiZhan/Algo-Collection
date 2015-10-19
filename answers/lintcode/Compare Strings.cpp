//@level Easy 
//@type Basic Implementation String LintCode Copyright
//@result Accepted Total Runtime: 34 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
		map<char, int> a_map;
		for (size_t i = 0; i < A.length(); ++ i) {
			if (a_map.end() == a_map.find(A[i])) {
				a_map.insert(make_pair(A[i], 0));
			}
			++ a_map[A[i]];
		}
		for (size_t i = 0; i < B.length(); ++ i) {
			if (a_map.end() == a_map.find(B[i])) {
				return false;
			}
			-- a_map[B[i]];
			if (a_map[B[i]] < 0) {
				return false;
			}
		}
		return true;
    }
};