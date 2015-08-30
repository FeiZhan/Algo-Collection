#include "include/acm_headers.h"
#include "include/leetcode_helper.h"
using namespace std;

class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (0 == strlen(needle)) {
			return 0;
		}
		//@note careful with unsigned
		for (size_t i = 0; i + strlen(needle) < strlen(haystack) + 1; ++ i) {
			if (haystack[i] != needle[0]) {
				continue;
			}
			bool flag = true;
			for (size_t j = 0; j < strlen(needle); ++ j) {
				if (haystack[i + j] != needle[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	Solution s;
	int ans = s.strStr("abb", "abaaa");
	std::cout << ans << std::endl;

	return 0;
}
