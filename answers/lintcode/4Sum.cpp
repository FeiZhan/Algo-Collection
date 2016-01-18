//@result Accepted Total Runtime: 15 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> num, int target) {
        // write your code here
		std::sort(num.begin(), num.end());
		vector<vector<int> > ans;
		for (size_t i = 0; i + 3 < num.size(); ++i) {
			vector<vector<int> > temp_ans = threeSum(num, i + 1, target - num[i]);
			for (size_t j = 0; j < temp_ans.size(); ++j) {
				temp_ans[j].insert(temp_ans[j].begin(), num[i]);
				ans.push_back(temp_ans[j]);
			}
			// skip duplicates
			while (i + 1 < num.size() && num[i] == num[i + 1]) {
				++i;
			}
		}
		return ans;
	}
	vector<vector<int> > threeSum(vector<int> &num, size_t begin, int target) {
		vector<vector<int> > ans;
		if (num.size() - begin < 3) {
			return ans;
		}
		for (size_t i = begin; i < num.size(); ++i) {
			// just search the right side
			size_t left = i + 1, right = num.size() - 1;
			while (left < num.size() && right < num.size() && left < right) {
				int sum = num[left] + num[right] + num[i];
				if (target == sum) {
					vector<int> temp;
					temp.push_back(num[i]);
					temp.push_back(num[left]);
					temp.push_back(num[right]);
					ans.push_back(temp);
					int temp1 = num[left];
					while (num[++left] == temp1) {}
				}
				else if (sum > target) {
					int temp = num[right];
					while (num[--right] == temp) {}
				}
				else if (sum < target) {
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
