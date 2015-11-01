//@type Binary Search Tree
//@result 30 / 30 test cases passed. Status: Accepted Runtime: 40 ms Submitted: 2 minutes ago You are here! Your runtime beats 86.13% of cpp submissions.

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		multiset<long long> num_set;
		k = min(k, int(nums.size()) - 1);
		for (long long i = 0; i < k && i < nums.size(); ++ i) {
			num_set.insert(nums[i]);
		}
		for (long long i = k; i < nums.size(); ++ i) {
			multiset<long long>::iterator it = num_set.lower_bound(nums[i]);
			//cout << "test " << i << " " << nums[i] << endl;
			//cout << "lower " << *it << " " << abs(*it - nums[i]) << " dist " << distance(it, num_set.end()) << endl;
			//cout << "compare " << (num_set.end() != it) << " " << (abs(*it - nums[i]) <= t) << endl;
			if ((num_set.end() != it && abs(*it - nums[i]) <= t) || (num_set.begin() != it && abs(*prev(it) - nums[i]) <= t)) {
				return true;
			}
			num_set.insert(nums[i]);
			if (num_set.size() > k) {
				pair<multiset<long long>::iterator, multiset<long long>::iterator> pit = num_set.equal_range(nums[i - k]);
				if(distance(pit.first, pit.second) > 0) {
					num_set.erase(pit.first);
				}
			}
		}
		return false;
	}
};