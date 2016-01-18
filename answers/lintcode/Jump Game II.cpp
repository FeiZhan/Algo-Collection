//@result Accepted Total Runtime: 36 ms 100% test cases passed.
//@algorithm greedy
// time is more strict than leetcode

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int count = 0;
        int reach = 0;
        int current = 0;
        for (int i = 0; i < A.size(); ++ i) {
            if (i > reach) {
                return -1;
            }
            else if (i > current) {
                current = reach;
                ++ count;
            }
            reach = max(reach, i + A[i]);
        }
        return count;
    }
};
