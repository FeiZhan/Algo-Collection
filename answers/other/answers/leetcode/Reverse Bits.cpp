#include <iostream>
using namespace std;

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

int main() {
	Solution s;
	cout << s.reverseBits(1) << endl;
	return 0;
}