//@type Array
//@result 17 / 17 test cases passed. Status: Accepted Runtime: 60 ms Submitted: 0 minutes ago You are here! Your runtime beats 59.65% of cpp submissions.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product(1);
		vector<int> product_list;
		for (size_t i = 0; i < nums.size(); ++ i) {
			product_list.push_back(product);
			product *= nums[i];
		}
		product = 1;
		for (size_t i = nums.size() - 1; i < nums.size(); -- i) {
			product_list[i] *= product;
			product *= nums[i];
		}
		return product_list;
    }
};