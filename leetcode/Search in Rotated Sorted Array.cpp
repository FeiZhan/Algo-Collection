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

//2015-1-4
// http://fisherlei.blogspot.ca/2013/01/leetcode-search-in-rotated-sorted-array.html
class Solution {
public:
	int search(int A[], int n, int target) {
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (A[mid] == target) {
				return mid;
			}
			if (A[mid] >= A[left]) {
				if (A[left] <= target && target < A[mid]) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			} else {
				if (A[mid] < target && target <= A[right]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
		}
		return -1;
	}
};
