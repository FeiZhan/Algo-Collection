class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
		size_t zero = 0;
		size_t two = nums.size() - 1;
		for (size_t i = 0; i <= two && i < nums.size(); ++ i) {
			if (0 == nums[i]) {
				nums[i] = nums[zero];
				nums[zero] = 0;
				++ zero;
			}
			else if (2 == nums[i]) {
				nums[i] = nums[two];
				nums[two] = 2;
				-- two;
				// move iterator backward, since the new item has not been examined
				-- i;
			}
		}
    }
};
