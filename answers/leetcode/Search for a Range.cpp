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
// 2014-04-22 AC recursive version
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ans = searchRange(A, 0, n, target);
		while (ans.size() < 2)
		{
			ans.push_back(-1);
		}
		return ans;
	}
	vector<int> searchRange(int A[], int left, int right, int target)
	{
		vector<int> ans;
		if (left >= right)
		{
			return ans;
		}
		int mid = (left + right) / 2;
		if (A[mid] < target)
		{
			return searchRange(A, mid + 1, right, target);
		}
		else if (A[mid] > target)
		{
			return searchRange(A, left, mid, target);
		}
		else
		{
			vector<int> right_ans = searchRange(A, mid + 1, right, target);
			vector<int> left_ans = searchRange(A, left, mid, target);
			if (left_ans.size() > 0)
			{
				ans.push_back(left_ans[0]);
			}
			else
			{
				ans.push_back(mid);
			}
			if (right_ans.size() >= 2)
			{
				ans.push_back(right_ans[1]);
			}
			else
			{
				ans.push_back(mid);
			}
		}
		return ans;
	}
};