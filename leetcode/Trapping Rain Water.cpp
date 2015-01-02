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

//2015-1-2
class Solution {
public:
	int trap(int A[], int n) {
		int sum = 0;
		stack<int> container_stack;
		for (int i = 0; i < n; ++ i) {
			int previous = 0;
			while (! container_stack.empty()) {
				int index = container_stack.top();
				sum += (std::min(A[index], A[i]) - previous) * (i - index - 1);
				if (A[index] > A[i]) {
					break;
				}
				container_stack.pop();
				previous = std::min(A[index], A[i]);
			}
			container_stack.push(i);
		}
		return sum;
	}
};
