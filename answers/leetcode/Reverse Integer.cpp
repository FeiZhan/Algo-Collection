//@result 1032 / 1032 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 44.23% of cpp submissions.

class Solution {
public:
    int reverse(int x) {
        if (INT_MIN == x) {
            return 0;
        }
        bool negative = x < 0;
        if (negative) {
            x = abs(x);
        }
        int reversed = 0;
        while (x) {
            if (reversed > INT_MAX / 10 || (INT_MAX / 10 == reversed && ! negative && x % 10 > INT_MAX % 10) || (INT_MAX / 10 == reversed && negative && x % 10 > INT_MAX % 10 + 1)) {
                reversed = 0;
                break;
            }
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return reversed * (negative ? -1 : 1);
    }
};
