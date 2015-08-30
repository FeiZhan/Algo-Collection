class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] > 0 && A[i] < n)
			{
				if (A[i] - 1 != i && A[A[i] - 1] != A[i])
				{
					int tmp = A[A[i] - 1];
					A[A[i] - 1] = A[i];
					A[i] = tmp;
					-- i;
				}
			}
		}
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] - 1 != i)
			{
				return i + 1;
			}
		}
		return n + 1;
    }
};
