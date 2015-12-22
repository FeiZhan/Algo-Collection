class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        // write your code here
        if (0 == nums.size()) {
            return 0;
        }
        bool min_flag = false;
        bool max_flag = false;
        int min_num = numeric_limits<int>::max();
        int max_num = numeric_limits<int>::min();
        for (size_t i = 0; i < nums.size(); ++ i) {
            if (numeric_limits<int>::min() == nums[i]) {
                min_flag = true;
            }
            if (numeric_limits<int>::max() == nums[i]) {
                max_flag = true;
            }
            min_num = min(min_num, nums[i]);
            max_num = max(max_num, nums[i]);
        }
        int length = (max_num - min_num) / nums.size() + 1;
        vector<pair<int, int> > gap_list((max_num - min_num) / length + 1, make_pair(numeric_limits<int>::max(), numeric_limits<int>::min()));
        for (size_t i = 0; i < nums.size(); ++ i) {
            size_t pos = (nums[i] - min_num) / length;
            gap_list[pos].first = min(gap_list[pos].first, nums[i]);
            gap_list[pos].second = max(gap_list[pos].second, nums[i]);
        }
        int max_gap = 0;
        size_t prev = 0;
        for (size_t i = 0; i < gap_list.size(); ++ i) {
            //cout << "gaps " << i << " " << gap_list[i].first << " " << gap_list[i].second << endl;
            if (numeric_limits<int>::max() != gap_list[i].first && numeric_limits<int>::min() != gap_list[i].second) {
                max_gap = max(max_gap, gap_list[i].second - gap_list[i].first);
                if (numeric_limits<int>::max() != gap_list[i].first && i > 0) {
                    max_gap = max(max_gap, gap_list[i].first - gap_list[prev].second);
                }
                prev = i;
            }
        }
        if (min_flag) {
            max_gap = max(max_gap, gap_list[0].first - numeric_limits<int>::min());
        }
        if (max_flag) {
            max_gap = max(max_gap, numeric_limits<int>::max() - gap_list[prev].second);
        }
        return max_gap;
    }
};
