class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        for (size_t i = 0; i + 2 < nums.size(); ++ i) {
            int temp = twoSumClosest(nums, i + 1, target - nums[i]);
            if (abs(closest) > abs(temp)) {
                closest = temp;
            }
        }
        return closest + target;
    }
    int twoSumClosest(const vector<int> nums, size_t start, int target) {
        int closest = INT_MAX;
        size_t left = start;
        size_t right = nums.size() - 1;
        while (left < right && right < nums.size()) {
            int temp = nums[left] + nums[right] - target;
            if (abs(temp) < abs(closest)) {
                closest = temp;
            }
            if (0 == temp) {
                break;
            }
            else if (temp > 0) {
                -- right;
            }
            else {
                ++ left;
            }
        }
        return closest;
    }
};
