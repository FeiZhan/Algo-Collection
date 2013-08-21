class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (0 == n)
		{
			return 0;
		}
		int mid = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] > A[mid])
			{
				mid = i;
			}
		}
		int h = 0, water = 0;
		for (int i = 0; i < mid; ++ i)
		{
			if (h > A[i])
			{
				water += h - A[i];
			} else
			{
				h = A[i];
			}
		}
		h = 0;
		for (int i = n - 1; i > mid; -- i)
		{
			if (h > A[i])
			{
				water += h - A[i];
			} else
			{
				h = A[i];
			}
		}
		return water;
    }
};
