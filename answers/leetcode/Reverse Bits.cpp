//@result Status: Accepted Runtime: 8 ms Submitted: 2 months, 4 weeks ago You are here! Your runtime beats 9.94% of cpp submissions.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans(0);
		for (int i = 0; i < 32; ++ i) {
			ans = (ans << 1) + (n % 2);
			n /= 2;
		}
		return ans;
    }
};
