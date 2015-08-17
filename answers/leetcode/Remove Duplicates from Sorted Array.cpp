#include <iostream>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
        {
			return 0;
		}
		int head = -1, last = -1, size = n, previous = A[0];
		for (int i = 1; i < n; ++ i)
		{
			if (A[i] == previous)
			{
				if (-1 == last)
				{
					head = i;
				} else
				{
					A[last] = i;
				}
				last = i;
				// record the previous one
				previous = A[i];
				A[i] = -1;
				-- size;
			} else
			{
				previous = A[i];
			}
		}
		int count = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (i == head)
			{
				++ count;
				head = A[head];
			} else
			{
		//std::cout << "head " << head << std::endl;
				A[i - count] = A[i];
			}
		}
		return size;
    }
    void output(const int A[], int n)
    {
		for (int i = 0; i < n; ++ i)
		{
			std::cout << A[i] << " ";
		}
		std::cout << std::endl;
	}
};
int main()
{
	Solution s;
	const int SIZE = 3;
	int A[SIZE] = {1, 1, 2};
	std::cout << s.removeDuplicates(A, SIZE) << std::endl;
	s.output(A, SIZE);
	return 0;
}
