// just greedy algorithm, not sound but works

class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int count = 0, begin = 0, reach = 0, next = 0;
		while (begin < n - 1)
		{
			if (begin + A[begin] >= n - 1)
			{
				return count + 1;
			}
			for (int i = begin; i <= begin + A[begin] && i < n; ++ i)
			{
				if (i + A[i] > next)
				{
					reach = i;
					next = i + A[i];
				}
			}
			if (reach == begin)
			{
				return INT_MAX;
			}
			++ count;
			if (reach >= n - 1)
			{
				return count;
			}
			begin = reach;
			next = 0;
		}
    }
};
