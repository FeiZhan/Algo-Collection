//@type Heap
//@result 18 / 18 test cases passed. Status: Accepted Runtime: 168 ms Submitted: 0 minutes ago You are here! Your runtime beats 14.72% of cpp submissions.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multimap<int, size_t> window_map;
		for (size_t i = 0; i + 1 < k && i < nums.size(); ++ i) {
			window_map.insert(make_pair(nums[i], i));
		}
		vector<int> max_list;
		for (size_t i = k - 1; i < nums.size(); ++ i) {
			window_map.insert(make_pair(nums[i], i));
			while (window_map.size() > 0 && window_map.rbegin()->second < i + 1 - k) {
				cout << "test " << window_map.rbegin()->second << " " << window_map.rbegin()->first << endl;
				window_map.erase(next(window_map.rbegin()).base());
			}
			max_list.push_back(window_map.rbegin()->first);
		}
		return max_list;
    }
};