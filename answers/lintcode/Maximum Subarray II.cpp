#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
		vector<int> left(nums.size(), INT_MIN);
		for (size_t i = 0; i < left.size(); ++ i) {
			left[i] = max((i > 0 ? left[i - 1] : 0) + nums[i], nums[i]);
		}
		for (size_t i = 0; i < left.size(); ++ i) {
			left[i] = max((i > 0 ? left[i - 1] : INT_MIN), left[i]);
		}
		vector<int> right(nums.size(), INT_MIN);
		for (size_t i = right.size() - 1; i < right.size(); -- i) {
			right[i] = max((i + 1 < right.size() ? right[i + 1] : 0) + nums[i], nums[i]);
		}
		for (size_t i = right.size() - 1; i < right.size(); -- i) {
			right[i] = max((i + 1 < right.size() ? right[i + 1] : INT_MIN), right[i]);
		}
		int max_two(INT_MIN);
		for (size_t i = 1; i < left.size(); ++ i) {
			//cout << "test " << i << " " << left[i] << " " << right[right.size() - 1 - i] << endl;
			max_two = max(max_two, left[i - 1] + right[i]);
		}
		return max_two;
    }
};

int main() {
	// your code goes here
	Solution s;
	vector<int> nums;
	//[1,3,-1,2,-1,2]
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(2);
	int ans = s.maxTwoSubArrays(nums);
	cout << ans << endl;
	return 0;
}