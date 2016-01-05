// 2014-12-14
//@result 1146 / 1146 test cases passed. Status: Accepted Runtime: 36 ms Submitted: 0 minutes ago You are here! Your runtime beats 13.45% of cpp submissions.

class Solution {
public:
    int minDistance(string word1, string word2) {
		if (0 == word1.length() || 0 == word2.length()) {
			return word1.length() + word2.length();
		}
		// rotation array is better
		std::vector<std::vector<int> > dp(word1.length(), std::vector<int>(word2.length(), INT_MAX));
		for (size_t i = 0; i < word1.length(); ++ i) {
			for (size_t j = 0; j < word2.length(); ++ j) {
				// be careful with size_t minus
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
					// don't forget
					if (i >= 1 && j >= 1) {
						dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + 1);
					}
				}
			}
		}
		/*for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 0; j < dp[i].size(); ++ j) {
				std::cout << i << " " << j << " : " << dp[i][j] << std::endl;
			}
		}*/
		return dp[word1.length() - 1][word2.length() - 1];
    }
};
