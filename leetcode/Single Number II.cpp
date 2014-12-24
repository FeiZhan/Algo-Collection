class Solution {
public:
	int singleNumber(int A[], int n) {
		vector<int> bit_list(32, 0);
		for (int i = 0; i < n; ++ i) {
			int num = A[i];
			int bit = 0;
			while (num && bit < bit_list.size()) {
				bit_list[bit] += num & 1;
				num >>= 1;
				++ bit;
			}
		}
		int ans = 0;
		for (size_t i = 0; i < bit_list.size(); ++ i) {
			if (bit_list[i] % 3) {
				ans |= 1 << i;
			}
		}
		return ans;
	}
};

class Solution {
public:
	int singleNumber(int A[], int n) {
		int one = 0, two = 0, three = 0;
		for (int i = 0; i < n; ++ i) {
			two |= one & A[i];
			one ^= A[i];
			three = one & two;
			one &= ~ three;
			two &= ~ three;
		}
		return one;
	}
};
