class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0, high = n - 1;
        while (low <= high)
        {
			int mid = (low + high) / 2;
			if (target < A[mid])
			{
				high = mid - 1;
			} else if (target > A[mid])
			{
				low = mid + 1;
			} else
			{
				if (target == A[low] && target == A[high])
				{
					vector<int> ans;
					ans.push_back(low);
					ans.push_back(high);
					return ans;
				}
				if (target > A[low])
				{
					++ low;
				}
				if (target < A[high])
				{
					-- high;
				}
			}
		}
		vector<int> ans;
		ans.push_back(-1);
		ans.push_back(-1);
		return ans;
    }
};
