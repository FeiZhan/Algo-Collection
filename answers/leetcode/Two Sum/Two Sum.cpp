//@result 16 / 16 test cases passed. Status: Accepted Runtime: 24 ms Submitted: 0 minutes ago You are here! Your runtime beats 38.08% of cpp submissions.
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		std::multimap<int, size_t> num_map;
		for (size_t i = 0; i < numbers.size(); ++ i) {
			num_map.insert(std::make_pair(numbers[i], i + 1));
		}
		vector<int> ans;
		for (std::multimap<int, size_t>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
			int diff = target - it->first;
			std::multimap<int, size_t>::iterator find_it = num_map.find(diff);
			if (find_it != num_map.end() && find_it != it) {
				ans.push_back(it->second);
				ans.push_back(find_it->second);
				break;
			}
		}
		std::sort(ans.begin(), ans.end());
		return ans;
    }
};

//@result 16 / 16 test cases passed. Status: Accepted Runtime: 24 ms Submitted: 0 minutes ago You are here! Your runtime beats 38.08% of cpp submissions.
// two pointers
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		multimap<int, size_t> num_map;
		for (size_t i = 0; i < numbers.size(); ++i) {
			num_map.insert(make_pair(numbers[i], i));
		}
		multimap<int, size_t>::iterator left_it = num_map.begin(), right_it = num_map.end();
		--right_it;
		while (left_it != right_it && left_it->first + right_it->first != target) {
			int sum = left_it->first + right_it->first;
			if (sum > target) {
				--right_it;
			}
			else if (sum < target) {
				++left_it;
			}
		}
		vector<int> ans;
		ans.push_back(left_it->second + 1);
		ans.push_back(right_it->second + 1);
		sort(ans.begin(), ans.end());
		return ans;
	}
};
