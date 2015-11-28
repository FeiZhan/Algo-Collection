//@WA

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        vector<vector<int> > subarray_list;
        for (size_t i = 0; i < nums.size(); ++ i) {
            vector<int> local(nums.size(), INT_MIN / 3);
            vector<int> global(nums.size(), INT_MIN / 3);
            for (size_t j = i; j < nums.size(); ++ j) {
                local[j] = max((j ? (local[j - 1] + nums[j]) : INT_MIN / 3), nums[j]);
                global[j] = max((j ? (global[j - 1]) : INT_MIN / 3), local[j]);
                //cout << "global " << i << " " << j << " " << global[j] << endl;
            }
            subarray_list.push_back(global);
        }
        vector<vector<int> > dp(nums.size(), vector<int> (k, INT_MIN / 3));
        for (size_t i = 0; i < nums.size(); ++ i) {
            for (int j = 0; j < k; ++ j) {
                if (0 == i) {
                    dp[i][j] = max(dp[i][j], subarray_list[0][i]);
                }
                for (size_t m = 0; m < i; ++ m) {
                    if (0 == j) {
                        dp[i][j] = max(dp[i][j], subarray_list[m][i]);
                        //cout << "debug " << i << " " << j << " " << dp[i][j] << " " << subarray_list[m][i] << endl;
                    }
                    else {
                        dp[i][j] = max(dp[i][j], dp[m][j - 1] + subarray_list[m + 1][i]);
                        //cout << "debug " << i << " " << j << " " << dp[i][j] << " " << subarray_list[m + 1][i] << endl;
                    }
                }
                //cout << "dp " << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp.back().back();
    }
};

int main() {
	// your code goes here
    Solution s;
    vector<int> nums;
    //[-1,-2,-3,-100,-1,-50], 2
    nums.push_back(4);
    nums.push_back(5);
    int k = 2;
    int ans = s.maxSubArray(nums, k);
    cout << ans << endl;
	return 0;
}
