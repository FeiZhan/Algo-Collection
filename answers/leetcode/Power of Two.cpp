//@time complexity O(1)
//@space complexity O(1)
//@result 1108 / 1108 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 7.51% of cpp submissions.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ! (n & (n - 1));
    }
};
