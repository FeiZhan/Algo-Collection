class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (n <= 2)
		{
			return n;
		}
		int head = -1, prev = -1;
		for (int i = 0; i < n - 2; ++ i)
		{
			// compare with next ones
			// if with previous ones, they may be changed.
			if (A[i] == A[i + 1] && A[i] == A[i + 2])
			{
				if (-1 == head)
				{
					head = i;
					prev = i;
				} else
				{
					A[prev] = i;
					prev = i;
				}
				A[i] = -1;
			}
		}
		int count = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (head == i)
			{
				++ count;
				head = A[head];
			} else
			{
				A[i - count] = A[i];
			}
		}
		return n - count;
    }
};
