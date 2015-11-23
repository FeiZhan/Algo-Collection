class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<pair<int, size_t> > sum_list;
        for (size_t i = 0; i < nums.size(); ++ i) {
            sum_list.push_back(make_pair(nums[i] + (0 == i ? 0 : sum_list.back().first), i));
        }
        sort(sum_list.begin(), sum_list.end());
        int closest = INT_MAX;
        vector<int> closest_list(2, 0);
        for (size_t i = 1; i < sum_list.size(); ++ i) {
            if (sum_list[i].first - sum_list[i - 1].first < closest) {
                closest = sum_list[i].first - sum_list[i - 1].first;
                closest_list[0] = sum_list[i].second;
                closest_list[1] = sum_list[i - 1].second;
            }
        }
        sort(closest_list.begin(), closest_list.end());
        if (closest_list[0] < closest_list[1]) {
            ++ closest_list[0];
        }
        return closest_list;
    }
};
