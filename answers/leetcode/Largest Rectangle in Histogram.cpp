// http://fisherlei.blogspot.ca/2012/12/leetcode-largest-rectangle-in-histogram.html
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		std::stack<int> height_stack;
		height.push_back(0);
		int largest = 0;
		for (int i = 0; i < height.size(); ++ i) {
			if (height_stack.empty() || height[i] > height[height_stack.top()]) {
				height_stack.push(i);
			} else {
				int last = height_stack.top();
				height_stack.pop();
				largest = std::max(largest, height[last] * (height_stack.empty() ? i : i - height_stack.top() - 1));  
				i --;  
			}
		}
		return largest;
	}
};
