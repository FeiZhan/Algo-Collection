//@result 45 / 45 test cases passed. Status: Accepted Runtime: 28 ms Submitted: 0 minutes ago You are here! Your runtime beats 15.61% of cpp submissions.

class Solution {
public:
    int maxArea(vector<int> &height) {
        int begin = 0, end = height.size() - 1;
        int max_area = 0;
        while (begin <= end && begin < height.size() && end >= 0) {
            max_area = std::max(max_area, std::min(height[begin], height[end]) * (end - begin));
            // come closer
            if (height[end] > height[begin]) {
                ++ begin;
            }
            else {
                -- end;
            }
        }
        return max_area;
    }
};
