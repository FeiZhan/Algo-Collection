class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
		if (k > nums.size() || k <= 0) {
			return 0;
		}
		return kthLargestElement(nums.size() - k + 1, nums, 0, nums.size() - 1);
    }
	int kthLargestElement(int k, vector<int> &nums, size_t begin, size_t end) {
		int pivot = nums[end];
		size_t left = begin;
		size_t right = end;
		while (true) {
			while (nums[left] < pivot && left < right) {
				++ left;
			}
			while (nums[right] >= pivot && right > left) {
				-- right;
			}
			if (left == right) {
				break;
			}
			swap(nums, left, right);
		}
		// one more swap
		swap(nums, left, end);
		// return value
		if (left + 1 == k) {
			return pivot;
		}
		else if (k < left + 1) {
			return kthLargestElement(k, nums, begin, left - 1);
		}
		else {
			return kthLargestElement(k, nums, left + 1, end);
		}
	}
	void swap(vector<int> &nums, size_t n0, size_t n1) {
		int temp = nums[n0];
		nums[n0] = nums[n1];
		nums[n1] = temp;
	}
};
