//@result TLE

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        multiset<int> window;
        vector<int> median_list;
        for (size_t i = 0; i < nums.size(); ++ i) {
            window.insert(nums[i]);
            while (window.size() > k) {
                pair<multiset<int>::iterator, multiset<int>::iterator> range = window.equal_range(nums[i - k]);
                if(range.first != range.second) {
                    window.erase(range.first);
                }
            }
            if (window.size() == k) {
                multiset<int>::iterator it = window.begin();
                for (size_t count = 0; it != window.end() && count * 2 + 2 < window.size(); ++ it, ++ count) {
                }
                if (window.end() != it) {
                    median_list.push_back(*it);
                }
            }
        }
        return median_list;
    }
};
