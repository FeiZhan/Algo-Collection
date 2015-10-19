//@level Medium 
//@type Binary Search LintCode Copyright
//@result Accepted Total Runtime: 11 ms 100% test cases passed.

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
		int left(1);
		int right(n);
		while (left < right) {
			int middle((left + right) / 2);
			if (VersionControl::isBadVersion(middle)) {
				right = middle;
			}
			else {
				left = middle + 1;
			}
		}
		return left;
    }
};

