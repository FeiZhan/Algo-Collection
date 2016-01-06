class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int closest_diff = INT_MAX;
        std::multimap<int, size_t> num_map;
        for (size_t i = 0; i < num.size(); ++ i) {
            num_map.insert(std::make_pair(num[i], 1));
        }
        for (std::multimap<int, size_t>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
            std::multimap<int, size_t>::iterator it1 = num_map.begin();
            std::multimap<int, size_t>::iterator it2 = num_map.end();
                    if (it1 == it) {
                        ++ it1;
                    }
            -- it2;
                    if (it2 == it) {
                        -- it2;
                    }
            while (it1 != num_map.end() && it2 != num_map.end() && it1 != it2) {
                int diff = it->first + it1->first + it2->first - target;
                //@note abs
                closest_diff = std::abs(closest_diff) > std::abs(diff) ? diff : closest_diff;
                if (diff > 0) {
                    -- it2;
                    if (it2 == it) {
                        -- it2;
                    }
                } else {
                    ++ it1;
                    if (it1 == it) {
                        ++ it1;
                    }
                }
            }
        }
        return target + closest_diff;
    }
};

// 2015-01-10
// two pointers
//@result 120 / 120 test cases passed. Status: Accepted Runtime: 28 ms Submitted: 0 minutes ago You are here! Your runtime beats 15.51% of cpp submissions.

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		std::sort(num.begin(), num.end());
		int closest = INT_MAX;
		int three_sum = 0;
		if (num.size() < 3) {
			return three_sum;
		}
		for (size_t i = 0; i < num.size(); ++i) {
			size_t left = i + 1, right = num.size() - 1;
			while (left < num.size() && right < num.size() && left < right) {
				int sum = num[left] + num[right] + num[i];
				if (std::abs(sum - target) < closest) {
					closest = std::abs(sum - target);
					three_sum = sum;
					int temp1 = num[left];
				}
				if (sum > target) {
					int temp = num[right];
					while (--right < num.size() && num[right] == temp) {}
				}
				else if (sum < target) {
					int temp1 = num[left];
					while (++left < num.size() && num[left] == temp1) {}
				}
				else {
					break;
				}
			}
			while (i + 1 < num.size() && num[i] == num[i + 1]) {
				++i;
			}
		}
		return three_sum;
	}
};
