// http://fisherlei.blogspot.ca/2013/04/leetcode-permutation-sequence-solution.html

class Solution {
public:
    string getPermutation(int n, int k) {
		int fact = 1;
		for (int i = 1; i < n; ++ i) {
			fact *= i;
		}
		std::vector<int> num_list;
		-- k;
		for (int i = n - 1; i >= 1; -- i) {
			num_list.push_back(k / fact);
			k %= fact;
			fact /= i;
		}
		std::vector<bool> flag_list(n, false);
		string perm;
		for (size_t i = 0; i < num_list.size(); ++ i) {
			for (size_t j = 0; j <= num_list[i] && j < flag_list.size(); ++ j) {
				num_list[i] += flag_list[j];
				//cout << num_list[i] << " " << j << ": " << flag_list[j] << endl;
			}
			if (num_list[i] < flag_list.size()) {
				perm += static_cast<char> (num_list[i] + '1');
				flag_list[num_list[i]] = true;
			}
		}
		for (size_t j = 0; j < flag_list.size(); ++ j) {
			if (! flag_list[j]) {
				perm += static_cast<char> (j + '1');
			}
		}
		return perm;
    }
};
