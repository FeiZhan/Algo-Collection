//@type Array Backtracking
//@result 18 / 18 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 2.37% of cpp submissions.

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
		set<int> current_list;
        return combinationSum3(1, current_list, k, n);
    }
    vector<vector<int>> combinationSum3(int begin, set<int> &current_list, int k, int n) {
		/*cout << "test ";
		for (set<int>::iterator it = current_list.begin(); it != current_list.end(); ++ it) {
			cout << *it << " ";
		}
		cout << "| " << n << endl;*/
		vector<vector<int> > combin_list;
		if (current_list.size() >= k) {
			if (0 == n) {
				vector<int> list(current_list.begin(), current_list.end());
				combin_list.push_back(list);
			}
			return combin_list;
		}
		for (int i = begin; i <= 9; ++ i) {
			if (i > n) {
				break;
			}
			if (current_list.end() != current_list.find(i)) {
				continue;
			}
			current_list.insert(i);
			vector<vector<int> > ans(combinationSum3(i + 1, current_list, k, n - i));
			combin_list.insert(combin_list.end(), ans.begin(), ans.end());
			current_list.erase(i);
		}
		return combin_list;
	}
};