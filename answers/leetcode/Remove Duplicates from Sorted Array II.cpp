class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (0 == n) {
			return n;
		}
		int duplicate = A[0];
		int count = 0;
		for (int i = 0; i < n; ++ i) {
			if (A[i] == duplicate) {
				++ count;
				if (count > 2) {
					for (int j = i + 1; j < n; ++ j) {
						A[j - 1] = A[j];
					}
					-- i;
					-- n;
				}
			} else {
				count = 1;
				duplicate = A[i];
			}
		}
		return n;
	}
};
