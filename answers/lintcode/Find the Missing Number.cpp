class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
		long long sum(0);
		for (size_t i = 0; i < nums.size(); ++ i) {
			sum += nums[i];
		}
		return nums.size() * (nums.size() + 1) / 2 - sum;
    }
};
