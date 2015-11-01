//@level Medium 
//@type Two Pointers Sort Array
//@result Accepted Total Runtime: 57 ms 100% test cases passed.

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
		set<vector<int> > threesum;
		multiset<int> num_set(nums.begin(), nums.end());
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size(); ++ i) {
			for (size_t j = i + 1; j < nums.size(); ++ j) {
				size_t count = num_set.count(- nums[i] - nums[j]);
				if (- nums[i] - nums[j] == nums[i]) {
					-- count;
				}
				if (- nums[i] - nums[j] == nums[j]) {
					-- count;
				}
				if (count > 0) {
					vector<int> three;
					three.push_back(nums[i]);
					three.push_back(nums[j]);
					three.push_back(- nums[i] - nums[j]);
					sort(three.begin(), three.end());
					threesum.insert(three);
				}
			}
		}
		return vector<vector<int> > (threesum.begin(), threesum.end());
    }
};

