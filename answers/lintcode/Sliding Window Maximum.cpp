class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> max_list;
        multiset<int> window;
        for (size_t i = 0; i < nums.size(); ++ i) {
            window.insert(nums[i]);
            while (window.size() > k) {
                pair<multiset<int>::iterator, multiset<int>::iterator> range = window.equal_range(nums[i - k]);
                if(distance(range.first, range.second) >= 1) {
                    window.erase(range.first);
                }
            }
            //cout << "debug " << i << " " <<window.size() << endl;
            if (window.size() >= k) {
                max_list.push_back(*window.rbegin());
            }
        }
        return max_list;
    }
};
