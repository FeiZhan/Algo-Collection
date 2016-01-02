//@type Dynamic Programming Heap Math
//@result 596 / 596 test cases passed. Status: Accepted Runtime: 44 ms Submitted: 1 minute ago You are here! Your runtime beats 29.04% of cpp submissions.

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n > ugly_list.size()) {
			if (0 == ugly_list.size()) {
				ugly_list.push_back(1);
				i2 = 0;
				i3 = 0;
				i5 = 0;
			}
			while (n > ugly_list.size()) {
				int num2(ugly_list[i2] * 2);
				int num3(ugly_list[i3] * 3);
				int num5(ugly_list[i5] * 5);
				int ugly(min(num2, min(num3, num5)));
				if (ugly != ugly_list.back()) {
					ugly_list.push_back(ugly);
				}
				if (ugly == num2) {
					++ i2;
				}
				else if (ugly == num3) {
					++ i3;
				}
				else if (ugly == num5) {
					++ i5;
				}
			}
		}
		return ugly_list[n - 1];
    }
	vector<int> ugly_list;
	size_t i2;
	size_t i3;
	size_t i5;
};