class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int max_area = 0;
        size_t left = 0;
        size_t right = heights.size() - 1;
        while (left < right && right < heights.size()) {
            max_area = max(max_area, int(min(heights[left], heights[right]) * (right - left)));
            if (heights[left] <= heights[right]) {
                ++ left;
            }
            else {
                -- right;
            }
        }
        return max_area;
    }
};
