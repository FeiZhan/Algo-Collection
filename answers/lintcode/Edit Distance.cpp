//@result Accepted Total Runtime: 46 ms 100% test cases passed.

class Solution {
public:
    int minDistance(string word1, string word2) {
		if (0 == word1.length() || 0 == word2.length()) {
			return word1.length() + word2.length();
		}
		std::vector<std::vector<int> > dp(word1.length(), std::vector<int>(word2.length(), INT_MAX));
		for (size_t i = 0; i < word1.length(); ++ i) {
			for (size_t j = 0; j < word2.length(); ++ j) {
				int diff = std::abs(static_cast<int>(i) - static_cast<int>(j));
				if (word1[i] == word2[j]) {
					if (i >= 1 && j >= 1) {
						dp[i][j] = dp[i - 1][j - 1];
					} else {
						dp[i][j] = diff;
					}
				} else {
					if (i >= 1) {
						dp[i][j] = dp[i - 1][j] + 1;
					} else {
						dp[i][j] = diff + 1;
					}
					if (j >= 1) {
						dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
					} else {
						dp[i][j] = std::min(dp[i][j], diff + 1);
					}
					if (i >= 1 && j >= 1) {
						dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + 1);
					}
				}
			}
		}
		return dp.back().back();
    }
};
