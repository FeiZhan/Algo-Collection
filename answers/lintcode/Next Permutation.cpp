//@result Runtime Error

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
		size_t change_pos(nums.size());
		for (size_t i = nums.size() - 2; i + 1 < nums.size(); -- i) {
			if (nums[i] < nums[i + 1]) {
				change_pos = i;
				break;
			}
		}
		if (nums.size() <= 2 || change_pos + 1 >= nums.size()) {
			sort(nums.begin(), nums.end(), greater<int> ());
		}
		else {
			size_t min_pos(change_pos + 1);
			for (size_t i = change_pos + 1; i < nums.size(); ++ i) {
				if (nums[i] > nums[change_pos] && nums[i] < nums[min_pos]) {
					min_pos = i;
				}
			}
			int temp = nums[change_pos];
			nums[change_pos] = nums[min_pos];
			nums[min_pos] = temp;
			sort(nums.begin() + change_pos + 1, nums.end());
		}
		return nums;
    }
};

int main() {
	// your code goes here
	Solution s;
	vector <int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	vector<int> ans = s.nextPermutation(nums);
	for (size_t i = 0; i < ans.size(); ++ i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}