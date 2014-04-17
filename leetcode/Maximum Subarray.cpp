class Solution {
public:
	// DP
	int maxSubArrayOld(int A[], int n) {
		if (0 == n)
		{
			return INT_MIN;
		}
		std::vector<int> max_list;
		max_list.push_back(A[0]);
		for (int i = 1; i < n; ++i)
		{
			max_list.push_back(max_list.back() >= 0 ? max_list.back() + A[i] : A[i]);
		}
		int ans = INT_MIN;
		for (size_t i = 0; i < max_list.size(); ++i)
		{
			if (max_list[i] > ans)
			{
				ans = max_list[i];
			}
		}
		return ans;
	}
	// divide and conquer
	int maxSubArray(int A[], int n) {
		if (0 == n)
		{
			return INT_MIN;
		}
		maxSubArray(A, 0, n);
	}
	int maxSubArray(int A[], int left, int right)
	{
		if (left >= right)
		{
			return INT_MIN;
		}
		int mid = (left + right) / 2;
		int left_sum = 0, left_max = INT_MIN;
		for (int i = mid; i >= left; --i)
		{
			left_sum += A[i];
			if (left_sum > left_max)
			{
				left_max = left_sum;
			}
		}
		int right_sum = 0, right_max = INT_MIN;
		for (int i = mid + 1; i < right; ++i)
		{
			right_sum += A[i];
			if (right_sum > right_max)
			{
				right_max = right_sum;
			}
		}
		int ans = left_max;
		if (right_max > 0)
		{
			ans += right_max;
		}
		int left_ans = maxSubArray(A, left, mid);
		int right_ans = maxSubArray(A, mid + 1, right);
		ans = (left_ans > ans) ? left_ans : ans;
		ans = (right_ans > ans) ? right_ans : ans;
		return ans;
	}
};