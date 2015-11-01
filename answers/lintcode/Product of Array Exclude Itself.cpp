class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
		vector<long long> forward(nums.size(), 1);
		vector<long long> backward(nums.size(), 1);
		for (size_t i = 0; i < nums.size(); ++ i) {
			forward[i] = nums[i] * (i > 0 ? forward[i - 1] : 1);
		}
		for (size_t i = nums.size() - 1; i < nums.size(); -- i) {
			backward[i] = nums[i] * (i + 1 < nums.size() ? backward[i + 1] : 1);
		}
		vector<long long> product(nums.size(), 0);
		for (size_t i = 0; i < product.size(); ++ i) {
			product[i] = (i > 0 ? forward[i - 1] : 1) * (i + 1 < product.size() ? backward[i + 1] : 1);
		}
		return product;
    }
};
