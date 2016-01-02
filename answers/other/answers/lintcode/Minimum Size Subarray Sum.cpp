class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        size_t left = 0;
        int sum = 0;
        int min_size = INT_MAX;
        for (size_t i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
            while (sum - nums[left] >= s) {
                sum -= nums[left];
                ++ left;
            }
            if (sum >= s) {
                min_size = min(min_size, int(i) - int(left) + 1);
            }
        }
        return INT_MAX == min_size ? -1 : min_size;
    }
};
