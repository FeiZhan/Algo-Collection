class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        std::vector<std::vector<int> > ans;
        if (num.size() < 3) {
            return ans;
        }
        std::map<int, int> num_map;
        for (size_t i = 0; i < num.size(); ++ i) {
            ++ num_map[num[i]];
        }
        int largest = num_map.rbegin()->first;
        for (std::map<int, int>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
            for (std::map<int, int>::iterator it1 = it; it1 != num_map.end() && it->first + it1->first <= largest; ++ it1) {
                if (it->second < 2 && it1 == it) {
                    continue;
                }
                if (- it->first - it1->first < it1->first) {
                    continue;
                }
                std::map<int, int>::iterator it2 = num_map.find(- it->first - it1->first);
                if (num_map.end() != it2 ) {
                    if ((it2 == it1 && it1->second < 2) || (it2 == it1 && it2 == it && it->second < 3)) {
                        continue;
                    }
                    std::vector<int> temp;
                    temp.push_back(it->first);
                    temp.push_back(it1->first);
                    temp.push_back(it2->first);
                    std::sort(temp.begin(), temp.end());
                    ans.push_back(temp);
                }
            }
        }
        //ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

// 2015-01-10
// two pointers
//@result 311 / 311 test cases passed. Status: Accepted Runtime: 76 ms Submitted: 0 minutes ago You are here! Your runtime beats 11.93% of cpp submissions.

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		std::sort(num.begin(), num.end());
		vector<vector<int> > ans;
		if (num.size() < 3) {
			return ans;
		}
		for (size_t i = 0; i < num.size(); ++i) {
			// just search the right side
			size_t left = i + 1, right = num.size() - 1;
			while (left < num.size() && right < num.size() && left < right) {
				int sum = num[left] + num[right] + num[i];
				if (0 == sum) {
					vector<int> temp;
					temp.push_back(num[i]);
					temp.push_back(num[left]);
					temp.push_back(num[right]);
					ans.push_back(temp);
					int temp1 = num[left];
					while (num[++left] == temp1) {}
				}
				else if (sum > 0) {
					int temp = num[right];
					while (num[--right] == temp) {}
				}
				else if (sum < 0) {
					int temp = num[left];
					while (num[++left] == temp) {}
				}
			}
			// skip duplicates
			while (i + 1 < num.size() && num[i] == num[i + 1]) {
				++i;
			}
		}
		return ans;
	}
};
