// http://fisherlei.blogspot.ca/2012/12/leetcode-distinct-subsequences_19.html
class Solution {
public:
    int numDistinct(string S, string T) {
		if (S.length() < T.length()) {
			return 0;
		}
		vector<vector<int> > dp(S.length(), vector<int> (T.length(), 0));
		for (size_t i = 0; i < S.length(); ++ i) {
			for (size_t j = 0; j < T.length(); ++ j) {
				dp[i][j] = i >= 1 ? dp[i - 1][j] : 0;
				if (S[i] == T[j]) {
					dp[i][j] += (i >= 1 && j >= 1) ? dp[i - 1][j - 1] : (j <= i);
				}
			}
		}
		for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 0; j < dp[i].size(); ++ j) {
				//cout << dp[i][j] << " ";
			}
			//cout << endl;
		}
		return dp[S.length() - 1][T.length() - 1];
    }
};
