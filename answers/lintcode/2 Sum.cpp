//@level Medium 
//@type Two Pointers Sort Array
//@result Accepted 100% Total Runtime: 9 ms 100% test cases passed.

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
		vector<int> sum_list;
		multiset<int> num_set(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size(); ++ i) {
			size_t count = num_set.count(target - nums[i]);
			if (nums[i] * 2 == target) {
				-- count;
			}
			if (count > 0) {
				for (size_t j = 0; j < nums.size(); ++ j) {
					if (i != j && nums[j] + nums[i] == target) {
						sum_list.push_back(min(i, j) + 1);
						sum_list.push_back(max(i, j) + 1);
						break;
					}
				}
				break;
			}
		}
		return sum_list;
    }
};

