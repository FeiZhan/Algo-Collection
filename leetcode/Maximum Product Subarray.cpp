class Solution {
public:
    int maxProduct(int A[], int n) {
		if (0 == n) {
			return 0;
		}
		int max = A[0], min = A[0];
		int all_max = max;
		for (int i = 1; i < n; ++ i) {
			// put them first, don't use polluted max, min
			int temp0 = max * A[i];
			int temp1 = min * A[i];
			// reset them
			max = A[i];
			min = A[i];
			if (temp0 > max) {
				max = temp0;
			}
			if (temp0 < min) {
				min = temp0;
			}
			if (temp1 > max) {
				max = temp1;
			}
			if (temp1 < min) {
				min = temp1;
			}
			if (max > all_max) {
				all_max = max;
			}
		}
		return all_max;
    }
};
