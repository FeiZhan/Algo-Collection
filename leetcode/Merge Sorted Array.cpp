// merge in reverse order
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int a_pos = m - 1, b_pos = n - 1, pos = m + n - 1;
		while (pos >= 0)
		{
			if (b_pos < 0 || (a_pos >= 0 && A[a_pos] > B[b_pos]))
			{
				A[pos] = A[a_pos];
				-- a_pos;
			} else
			{
				A[pos] = B[b_pos];
				-- b_pos;
			}
			-- pos;
		};
    }
};
