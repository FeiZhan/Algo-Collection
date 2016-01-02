#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	k %= nums.size();
        for (size_t i = 0; i < nums.size() / 2; ++ i) {
        	int temp(nums[i]);
        	nums[i] = nums[nums.size() - i - 1];
        	nums[nums.size() - i - 1] = temp;
        }
        for (size_t i = 0; i < k / 2 && i < nums.size(); ++ i) {
        	int temp(nums[i]);
        	nums[i] = nums[k - i - 1];
        	nums[k - i - 1] = temp;
        }
        for (size_t i = 0; i < (nums.size() - k) / 2; ++ i) {
        	int temp(nums[i + k]);
        	nums[i + k] = nums[nums.size() - i - 1];
        	nums[nums.size() - i - 1] = temp;
        }
    }
};

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	s.rotate(nums, 1);
	for (size_t i = 0; i < nums.size(); ++ i) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}