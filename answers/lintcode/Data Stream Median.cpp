//@level Hard 
//@type LintCode Copyright Heap Priority Queue
//@result Accepted Total Runtime: 59 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
		vector<int> median_list;
		priority_queue<int> smaller;
		priority_queue<int, std::vector<int>, std::greater<int> > larger;
		if (0 == nums.size()) {
			return median_list;
		}
		smaller.push(nums[0]);
		median_list.push_back(nums[0]);
		for (size_t i = 1; i < nums.size(); ++ i) {
			if (nums[i] < smaller.top()) {
				smaller.push(nums[i]);
			}
			else {
				larger.push(nums[i]);
			}
			while (smaller.size() < larger.size()) {
				int temp(larger.top());
				larger.pop();
				smaller.push(temp);
			}
			while (smaller.size() > larger.size() + 1) {
				int temp(smaller.top());
				smaller.pop();
				larger.push(temp);
			}
			median_list.push_back(smaller.top());
		}
		return median_list;
    }
};

