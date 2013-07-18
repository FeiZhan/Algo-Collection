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
