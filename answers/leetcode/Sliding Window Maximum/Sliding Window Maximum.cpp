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

//@algorithm deque
//@time complexity O(n)
//@space complexity O(k)
//@result 18 / 18 test cases passed. Status: Accepted Runtime: 108 ms Submitted: 0 minutes ago You are here! Your runtime beats 25.65% of cpp submissions.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_window;
        deque<size_t> window;
        for (size_t i = 0; i < nums.size(); ++ i) {
            // not in the window
            while (i >= k && window.size() > 0 && window.front() <= i - k) {
                window.pop_front();
            }
            // too small
            while (window.size() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
            if (i + 1 >= k) {
                max_window.push_back(nums[window.front()]);
            }
        }
        return max_window;
    }
};
