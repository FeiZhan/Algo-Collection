class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        stack<size_t> height_stack;
        int largest = 0;
        for (size_t i = 0; i < height.size(); ++ i) {
            if (height_stack.empty() || height[height_stack.top()] < height[i]) {
                height_stack.push(i);
            }
            else {
                size_t temp = height_stack.top();
                height_stack.pop();
                largest = max(largest, height[temp] * (int)(height_stack.empty() ? i : i - height_stack.top() - 1));
                -- i;
            }
        }
        while (! height_stack.empty()) {
            size_t temp = height_stack.top();
            height_stack.pop();
            largest = max(largest, height[temp] * (int)(height_stack.empty() ? height.size() : height.size() - height_stack.top() - 1));
        }
        return largest;
    }
};
