//@type Divide and Conquer Heap
//@result 27 / 27 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago

#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
    }
};

int main() {
	// your code goes here
	return 0;
}