class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int low = 0, high = n - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (target == A[mid])
			{
				return mid;
			} else if (target < A[mid])
			{
				high = mid - 1;
			} else
			{
				low = mid + 1;
			}
		}
		int mid = (low + high) / 2;
		if (target < A[mid])
		{
			// may result in mid - 1 == -1
			if (0 >= mid)
			{
				return 0;
			} else
			{
				return mid - 1;
			}
		} else
		{
			return mid + 1;
		}
    }
};
// 2014-04-20 AC, recursive binary search
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		return searchInsert(A, 0, n, target);
    }
    int searchInsert(int A[], int left, int right, int target) {
		if (left >= right)
		{
			return right;
		}
		int mid = (left + right) / 2;
		if (A[mid] == target)
		{
			return mid;
		}
		else if (target > A[mid])
		{
			return searchInsert(A, mid + 1, right, target);
		}
		else
		{
			return searchInsert(A, left, mid, target);
		}
	}
};
