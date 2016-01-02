class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> nums = numbers;
        sort(nums.begin(), nums.end());
        int nonneg;
        for (int i = 0; i < nums.size(); ++ i)
        {
			if (nums[i] >= 0)
			{
				nonneg = i;
				break;
			}
		}
		vector<int> ans;
		for (int i = 0; i < nums.size(); ++ i)
		{
			if (nums[i] <= target)
			{
				for (int j = nonneg; j < nums.size(); ++ j)
				{
					if (nums[i] + nums[j] == target)
					{
						for (int k = 0; k < numbers.size(); ++ k)
						{
							if (nums[i] == numbers[k])
							{
								ans.push_back(k + 1);
								break;
							}
						}
						for (int k = 0; k < numbers.size(); ++ k)
						{
							if (nums[j] == numbers[k] && k+1 != ans[0])
							{
								ans.push_back(k + 1);
								break;
							}
						}
						sort(ans.begin(), ans.end());
						return ans;
					} else if (nums[i] + nums[j] > target)
					{
						break;
					}
				}
			} else
			{
				for (int j = nonneg - 1; j >= 0; -- j)
				{
					if (nums[i] + nums[j] == target)
					{
						for (int k = 0; k < numbers.size(); ++ k)
						{
							if (nums[i] == numbers[k])
							{
								ans.push_back(k + 1);
								break;
							}
						}
						for (int k = 0; k < numbers.size(); ++ k)
						{
							if (nums[j] == numbers[k] && k+1 != ans[0])
							{
								ans.push_back(k + 1);
								break;
							}
						}
						sort(ans.begin(), ans.end());
						return ans;
					} else if (nums[i] + nums[j] < target)
					{
						break;
					}
				}
			}
		}
		return ans;
    }
};

// 2014-12-14
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

// 2015-01-10
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