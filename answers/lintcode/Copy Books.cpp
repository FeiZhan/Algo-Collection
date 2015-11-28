class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        vector<int> sum_list;
        for (size_t i = 0; i < pages.size(); ++ i) {
            sum_list.push_back(pages[i] + (i ? sum_list.back() : 0));
        }
        vector<vector<int> > dp(pages.size(), vector<int> (k, INT_MAX));
        for (size_t i = 0; i < pages.size(); ++ i) {
            for (int j = 0; j < k; ++ j) {
                for (size_t m = 0; m <= i; ++ m) {
                    dp[i][j] = min(dp[i][j], max((j ? dp[m][j - 1] : 0), sum_list[i] - ((i > m && j) ? sum_list[m] : 0)));
                }
                //cout << "debug " << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp.back().back();
    }
};
