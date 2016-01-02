//@type Divide and Conquer Heap
//@todo QuickSelect algorithm

//@result 27 / 27 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
    }
};

//@time complexity O(n * logk)
//@space complexity O(k)
//@result 27 / 27 test cases passed. Status: Accepted Runtime: 16 ms You are here! Your runtime beats 6.36% of cpp submissions.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > heap;
        for (size_t i = 0; i < nums.size(); ++ i) {
            heap.push(nums[i]);
            while (heap.size() > k) {
                heap.pop();
            }
        }
        return heap.size() ? heap.top() : 0;
    }
};
