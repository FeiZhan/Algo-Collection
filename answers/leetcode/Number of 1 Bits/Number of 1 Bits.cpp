//@type  Bit Manipulation
//@result 600 / 600 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 64.11% of cpp submissions.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            ++ count;
        }
        return count;
    }
};
