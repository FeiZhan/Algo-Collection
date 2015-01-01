class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > ans;
		if (0 == num.size()) {
			return ans;
		}
		std::sort(num.begin(), num.end());
		for (size_t i = num.size() - 1; i > 2; -- i) {
			if (num.size() - 1 == i || num[i] != num[i + 1]) {
				vector<vector<int> > temp_ans = threeSum(num, i - 1, target - num[i]);
				for (size_t j = 0; j < temp_ans.size(); ++ j) {
					temp_ans[j].push_back(num[i]);
					ans.push_back(temp_ans[j]);
				}
			}
		}
		return ans;
	}
	vector<vector<int> > threeSum(vector<int> &num, size_t end, int target) {
		vector<vector<int> > ans;
		for (size_t i = end; i > 1; -- i) {
			if (i == end || num[i] != num[i + 1]) {
				vector<vector<int> > temp_ans = twoSum(num, i - 1, target - num[i]);
				for (size_t j = 0; j < temp_ans.size(); ++ j) {
					temp_ans[j].push_back(num[i]);
					ans.push_back(temp_ans[j]);
				}
			}
		}
		return ans;
	}
	vector<vector<int> > twoSum(vector<int> &num, size_t end, int target) {
		vector<vector<int> > ans;
		size_t left = 0, right = end;
		while (left < right) {
			if (num[left] + num[right] == target) {
				vector<int> two_list;
				two_list.push_back(num[left]);
				two_list.push_back(num[right]);
				ans.push_back(two_list);
				++ left;
				-- right;
				while (left < right && num[left] == num[left - 1]) {
					++ left;
				}
				while (left < right && num[right] == num[right + 1]) {
					-- right;
				}
			}
			else if (num[left] + num[right] > target) {
				-- right;
			}
			else {
				++ left;
			}
		}
		return ans;
	}
	void print(const vector<vector<int> > &matrix) {
		for (size_t i = 0; i < matrix.size(); ++ i) {
			for (size_t j = 0; j < matrix[i].size(); ++ j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
