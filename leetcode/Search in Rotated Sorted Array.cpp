class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 >= n)
        {
			return -1;
		}
		int low = 0, high = n - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (target == A[mid])
			{
				return mid;
			}
			if (A[low] > A[mid])
			{
				if (target < A[mid])
				{
					high = mid - 1;
				}
				// note equal: comparison between target and A[low] may be equal, we should not move low when equal
				else if (target >= A[low])
				{
					high = mid - 1;
				} else
				{
					low = mid + 1;
				}
			} else
			{
				if (target > A[mid])
				{
					low = mid + 1;
				} else if (target >= A[low])
				{
					high = mid - 1;
				} else
				{
					low = mid + 1;
				}
			}
		}
		return -1;
    }
};
