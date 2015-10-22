//@result Accepted Total Runtime: 15 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
		vector<vector<int> >set_list;
		for (size_t i = 0; i < (1 << nums.size()); ++ i) {
			vector<int> set;
			for (size_t j = 0; j < nums.size(); ++ j) {
				if ((i >> j) & 1) {
					set.push_back(nums[j]);
				}
			}
			set_list.push_back(set);
		}
		return set_list;
    }
};
