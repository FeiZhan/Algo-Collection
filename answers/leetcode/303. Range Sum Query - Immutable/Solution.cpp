class NumArray {
public:
    NumArray(vector<int> &nums) {
    	sum_list.clear();
        for (size_t i = 0; i < nums.size(); ++ i) {
        	sum_list.push_back(nums[i] + (sum_list.size() ? sum_list.back() : 0));
        }
    }

    int sumRange(int i, int j) {
        return sum_list[j] - (i ? sum_list[i - 1] : 0);
    }
    vector<int> sum_list;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);