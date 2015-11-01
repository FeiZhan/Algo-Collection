//@level Easy
//@type Binary Search Array
//@result Accepted Total Runtime: 158 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
		long long left(0);
		long long right(array.size() - 1);
		while (left <= right) {
			long long middle = left + (right - left) / 2;
			if (array[middle] == target) {
				// avoid duplicate
				if (left == right) {
					return middle;
				}
				else {
					right = middle;
				}
			}
			else if (array[middle] > target) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
        return -1;
    }
};