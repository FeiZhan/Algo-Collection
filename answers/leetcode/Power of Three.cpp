//@result 21038 / 21038 test cases passed. Status: Accepted Runtime: 140 ms Submitted: 0 minutes ago You are here! Your runtime beats 58.98% of cpp submissions.

class Solution {
public:
    bool isPowerOfThree(int n) {
        double log3 = log10(n) / log10(3);
        return log3 == int(log3);
    }
};
