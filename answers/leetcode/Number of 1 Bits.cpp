//@type  Bit Manipulation
//@result 600 / 600 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count(0);
		while (n) {
			count += n % 2;
			n /= 2;
		}
		return count;
    }
};

int main() {
	// your code goes here
	return 0;
}